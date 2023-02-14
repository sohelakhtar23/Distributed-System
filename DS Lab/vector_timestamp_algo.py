import pprint

processList = []
logicalClock = {}
timeStamp = {}
processIndexAdd = {}


def addProcess():
    pName = input("Enter 3 Processes Name seperated by space: ")
    processList = pName.split()
    for process in processList:
        logicalClock[process] = (0, 0, 0)

    for i in range(0, len(processList)):
        dummy_list = [0, 0, 0]
        dummy_list[i] = 1
        processIndexAdd[processList[i]] = tuple(dummy_list)

    print(logicalClock, processIndexAdd, sep="\n")

# tuple(map(sum, zip(a, b)))


def addEvent():
    pName = input("Enter the Process for which you want to add an event: ")
    eName = input('Enter Event name: ')
    etype = input("Enter the event type(normal/message): ")
    if etype == "normal":
        logicalClock[pName] = tuple(
            map(sum, zip(logicalClock[pName], processIndexAdd[pName])))
        timeStamp[eName] = logicalClock[pName]
    if etype == "message":
        logicalClock[pName] = tuple(
            map(sum, zip(logicalClock[pName], processIndexAdd[pName])))
        timeStamp[eName] = logicalClock[pName]
        sendmessage(timeStamp[eName])


def sendmessage(t):
    eName = input("Enter the Event which will receive the message: ")
    pName = input("Enter the process on which this event will occur: ")

    dummyList = list(logicalClock[pName])
    for i in range(3):
        if t[i] > logicalClock[pName][i]:
            dummyList[i] = t[i]
    logicalClock[pName] = tuple(
        map(sum, zip(dummyList, processIndexAdd[pName])))
    timeStamp[eName] = logicalClock[pName]


def display():
    pprint.pprint(timeStamp)


if __name__ == "__main__":
    addProcess()
    while(1):
        print("\n1.ADD EVENT\n2.DISPLAY TIMESTAMP\n3.EXIT")
        n = int(input("Enter your choice: "))
        if n == 1:
            addEvent()
        elif n == 2:
            display()
        else:
            break
