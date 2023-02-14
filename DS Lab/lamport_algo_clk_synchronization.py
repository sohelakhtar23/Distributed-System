import sys
import pprint

processList = []
logicalClock = {}
timeStamp = {}


def addProcess():
    pName = input("Enter Processes Name seperated by space: ")
    processList = pName.split()
    for process in processList:
        logicalClock[process] = 0


def addEvent():
    pName = input("Enter the Process for which you want to add an event: ")
    eName = input('Enter Event name: ')
    etype = input("Enter the event type(normal/message): ")
    if etype == "normal":
        timeStamp[eName] = logicalClock[pName]+1
        logicalClock[pName] += 1
    if etype == "message":
        timeStamp[eName] = logicalClock[pName]+1
        logicalClock[pName] += 1
        sendmessage(timeStamp[eName])


def sendmessage(t):
    eName = input("Enter the Event which will receive the message: ")
    pName = input("Enter the process on which this event will occur: ")
    if t > logicalClock[pName]:
        logicalClock[pName] = t
    timeStamp[eName] = logicalClock[pName]+1
    logicalClock[pName] += 1


def display():
    pprint.pprint(timeStamp)


if __name__ == "__main__":
    addProcess()
    while(1):
        print("1.ADD EVENT\n2.DISPLAY TIMESTAMP\n3.EXIT")
        n = int(input("Enter your choice: "))
        if n == 1:
            addEvent()
        elif n == 2:
            display()
        else:
            sys.exit("BYE")
