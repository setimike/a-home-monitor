import serial, time

htmlHeader = '''<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"> 
<html> 
<head> 
  <meta content="text/html; charset=ISO-8859-1" http-equiv="content-type">
  <meta http-equiv="refresh" content="110">
  <title>Weather</title> 
</head>
'''

weatherPage = '''<body>
<h1>Living Room:</h1>
<h3>Time: %d:%02d</h3>
<h2>Temperature: %s</h2>
<h2>Humidity: %s percent</h2>
<h2>Motion last detected at: %s</h2>
<h2>Light level: %s</h2>
</body>
</html>'''

htmlfile = '/var/www/weather.html'
ser = serial.Serial('/dev/ttyACM0', 9600)
ser.readline()
fmt = "./Temp-%4d-%02d-%02d-%02d-%02d.csv"
runTempF = 0
curTempF = 0
runLight = 0
curLight = 0
runHumidity = 0
curHumidity = 0
runMotion = 0
curMotion = 0
lastMotion = "Never"

while True:
	curHour = time.localtime()[3]
	runHour = curHour
	filename = fmt % time.localtime()[0:5]
	f = open(filename, 'wb')
	
	while curHour == runHour:
		curHour, curMinute = time.localtime()[3:5]
		runMinute = curMinute
		while curMinute == runMinute:
			curMinute = time.localtime()[4]
			rawrow = ser.readline()
			f.write(rawrow)
			tmprow = rawrow.split(',')
			# process read line into data:
			try:
				readLight = int(tmprow[0])
				runHumidity = float(tmprow[1])
				runTempF = float(tmprow[2])
				readMotion = int(tmprow[3])
				if readLight > runLight:
					runLight = readLight
				if readMotion > runMotion:
					runMotion = readMotion
			except (IndexError, ValueError):
				curMinute = runMinute
			time.sleep(5)
		changed = 0
		if runTempF != curTempF:
			curTempF = runTempF
			changed = 1
		if runLight != curLight:
			curLight = runLight
			changed = 1
		if runHumidity != curHumidity:
			curHumidity = runHumidity
			changed = 1
		if runMotion:
			lastMotion = "%02d:%02d" % (curHour, curMinute)
		if runMotion != curMotion:
			curMotion = runMotion
			changed = 1
		if changed:
			tempPage = weatherPage % (curHour, curMinute,curTempF,curHumidity, lastMotion, curLight)
			print "Time %d:%02d" % (curHour, curMinute)
			print "Temperature: %s" % (curTempF)
			print "Humidity: %s percent" % (curHumidity)
			print "Motion last detected at: %s" % (lastMotion)
			print "Light level: %s" % (curLight)
			print "\n\n"
			uploadPage = htmlHeader + tempPage
			hf = file(htmlfile,"w")
			hf.write(uploadPage)
			hf.close
#		else:
#			print "#Diag: No temp change"
		runLight = 0
		runHumidity = 0
		runTempF = 0
		runMotion = 0

		if curHour > runHour:
			runHour = curHour
	# end of loop
	f.close()
