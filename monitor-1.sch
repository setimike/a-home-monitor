v 20110115 2
C 40000 40000 0 0 0 title-B.sym
C 42100 44300 1 0 0 ground.sym
C 40600 46000 1 0 0 in-1.sym
{
T 40600 46300 5 10 0 0 0 0 1
device=INPUT
T 40600 46300 5 10 1 1 0 0 1
refdes=Analog Voltage
}
C 42400 44600 1 90 0 resistor-1.sym
{
T 42000 44900 5 10 0 0 90 0 1
device=RESISTOR
T 42100 44800 5 10 1 1 90 0 1
refdes=10Kohm
}
C 42100 47500 1 0 0 5V-plus-1.sym
N 42300 45500 42300 46600 4
N 41200 46100 42300 46100 4
C 42600 46600 1 90 0 photo-resistor-1.sym
{
T 41900 47300 5 10 0 0 90 0 1
device=PHOTORESISTOR
T 41900 46800 5 10 1 1 90 0 1
refdes=PhotoCell
}
C 47800 45500 1 0 0 connector3-1.sym
{
T 49600 46400 5 10 0 0 0 0 1
device=CONNECTOR_3
T 47800 46600 5 10 1 1 0 0 1
refdes=PIR
}
C 49800 47500 1 0 0 5V-plus-1.sym
C 49800 44300 1 0 0 ground.sym
C 50800 47800 1 270 0 in-1.sym
{
T 51100 47800 5 10 0 0 270 0 1
device=INPUT
T 51100 47800 5 10 1 1 270 0 1
refdes=DigitalIn
}
C 51000 46300 1 90 0 resistor-1.sym
{
T 50600 46600 5 10 0 0 90 0 1
device=RESISTOR
T 50700 46500 5 10 1 1 90 0 1
refdes=10K Ohm
}
N 49500 46300 50000 46300 4
N 50000 46300 50000 47500 4
N 49500 45700 50000 45700 4
N 50000 45700 50000 44600 4
N 49500 46000 50900 46000 4
N 50900 46000 50900 46300 4
T 50400 40900 9 10 1 0 0 0 1
Home Monitor Project
T 54100 40300 9 10 1 0 0 0 1
0.2
T 50100 40300 9 10 1 0 0 0 1
monitor-1.sch
T 50600 40000 9 10 1 0 0 0 1
1
T 51600 40000 9 10 1 0 0 0 1
1
C 43800 45400 1 0 0 connector3-1.sym
{
T 45600 46300 5 10 0 0 0 0 1
device=CONNECTOR_3
T 43800 46500 5 10 1 1 0 0 1
refdes=TMP36
}
C 45600 44200 1 0 0 ground.sym
C 46600 47700 1 270 0 in-1.sym
{
T 46900 47700 5 10 0 0 270 0 1
device=INPUT
T 46900 47700 5 10 1 1 270 0 1
refdes=AnalogIn
}
N 45300 46200 45800 46200 4
N 45800 46200 45800 47400 4
N 45300 45600 45800 45600 4
N 45800 45600 45800 44500 4
N 45300 45900 46700 45900 4
N 46700 45900 46700 47100 4
C 45600 47400 1 0 0 3.3V-plus-1.sym