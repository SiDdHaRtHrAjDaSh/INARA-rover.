import curses
import RPi.GPIO as GPIO
from time import sleep
from picamera import PiCamera

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
motor1a=7
motor1b=11
motor1c=22
motor2a=13
motor2b=16
motor2c=15
motor3a=29
motor3b=31
motor3c=32
motor4a=33
motor4b=35
motor4c=36

GPIO.setup(motor1a,GPIO.OUT)
GPIO.setup(motor1b,GPIO.OUT)
GPIO.setup(motor1c,GPIO.OUT)
GPIO.setup(motor2a,GPIO.OUT)
GPIO.setup(motor2b,GPIO.OUT)
GPIO.setup(motor2c,GPIO.OUT)
GPIO.setup(motor3a,GPIO.OUT)
GPIO.setup(motor3b,GPIO.OUT)
GPIO.setup(motor3c,GPIO.OUT)
GPIO.setup(motor4a,GPIO.OUT)
GPIO.setup(motor4b,GPIO.OUT)
GPIO.setup(motor4c,GPIO.OUT)

screen=curses.initscr()
curses.noecho()
curses.cbreak()
curses.halfdelay(3)
screen.keypad(True)


while True:
	char=screen.getch()
	if char == ord('q'):
		break
	elif char==ord('d'):
		GPIO.output(motor1a,GPIO.HIGH)
		GPIO.output(motor1b,GPIO.LOW)
		GPIO.output(motor1c,GPIO.HIGH)
		GPIO.output(motor2a,GPIO.HIGH)
		GPIO.output(motor2b,GPIO.LOW)
		GPIO.output(motor2c,GPIO.HIGH)
	elif char==ord('a'):
		GPIO.output(motor1a,GPIO.LOW)
		GPIO.output(motor1b,GPIO.HIGH)
		GPIO.output(motor1c,GPIO.HIGH)
		GPIO.output(motor2a,GPIO.LOW)
		GPIO.output(motor2b,GPIO.HIGH)
		GPIO.output(motor2c,GPIO.HIGH)
	elif char==ord('s'):
		GPIO.output(motor1a,GPIO.HIGH)
		GPIO.output(motor1b,GPIO.LOW)
		GPIO.output(motor1c,GPIO.HIGH)
		GPIO.output(motor2a,GPIO.LOW)
		GPIO.output(motor2b,GPIO.HIGH)
		GPIO.output(motor2c,GPIO.HIGH)
	elif char==ord('w'):
		GPIO.output(motor1a,GPIO.LOW)
		GPIO.output(motor1b,GPIO.HIGH)
		GPIO.output(motor1c,GPIO.HIGH)
		GPIO.output(motor2a,GPIO.HIGH)
		GPIO.output(motor2b,GPIO.LOW)
		GPIO.output(motor2c,GPIO.HIGH)
	elif char==10:
		GPIO.output(motor1a,GPIO.LOW)
		GPIO.output(motor1b,GPIO.LOW)
		GPIO.output(motor1c,GPIO.LOW)
		GPIO.output(motor2a,GPIO.LOW)
		GPIO.output(motor2b,GPIO.LOW)
		GPIO.output(motor2c,GPIO.LOW)

	elif char==10:
		GPIO.output(motor1a,GPIO.LOW)
		GPIO.output(motor1b,GPIO.LOW)
		GPIO.output(motor1c,GPIO.LOW)
		GPIO.output(motor2a,GPIO.LOW)
		GPIO.output(motor2b,GPIO.LOW)
		GPIO.output(motor2c,GPIO.LOW)
		GPIO.output(motor3a,GPIO.LOW)
		GPIO.output(motor3b,GPIO.LOW)
		GPIO.output(motor3c,GPIO.LOW)
		GPIO.output(motor4a,GPIO.LOW)
		GPIO.output(motor4b,GPIO.LOW)
		GPIO.output(motor4c,GPIO.LOW)
	elif char==ord('c'):
		camera = PiCamera()
		camera.start_preview()	
curses.nocbreak();screen.keypad(0);curses.echo()
curses.endwin()
GPIO.cleanup()


