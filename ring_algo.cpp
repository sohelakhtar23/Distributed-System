#include <iostream>
using namespace std;
#define MAX 20

int process[MAX], n, leader;
void display();
void ring();

int main()
{
    int fchoice, i;
    cout << "Enter no. of processes : ";
    cin >> n;
    cout << endl
         << "Enter processes state below, i.e alive or dead (1/0)" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "for Process " << i << " : ";
        cin >> process[i];
        if (process[i])
            leader = i;
    }

    display();
    do
    {
        cout << "\n1.RING Algorithm \t2.DISPLAY \t3.EXIT\n";
        cout << "Enter your choice : ";
        cin >> fchoice;
        switch (fchoice)
        {
        case 1:
            ring();
            break;

        case 2:
            display();
            break;

        case 3:
            break;

        default:
            break;
        }
    } while (fchoice != 3);

    return 0;
}

void display()
{
    int i;
    cout << "\nProcess :  ";
    for (i = 0; i < n; i++)
        cout << "\t" << i;

    cout << "\nAlive   :  ";
    for (i = 0; i < n; i++)
        cout << "\t" << process[i];
    cout << endl
         << "LEADER is => " << leader << endl
         << endl;
}


// Implementing RING Algorithm ======================================================
void ring()
{
    int schoice, crash, activate, i, gid, flag, subLeader;
    do
    {
        cout << "\n1.CRASH \t2.ACTIVATE \t3.DISPLAY \t4.EXIT\n";
        cout << "Enter your choice ";
        cin >> schoice;
        switch (schoice)
        {
        case 1:
            cout << "\nEnter process to crash : ";
            cin >> crash;

            if (process[crash])
                process[crash] = 0;
            else
                cout << "Process " << crash << " is already dead!" << endl;
            do
            {
                cout << "Enter election generator id : ";
                cin >> gid;
                if (gid == leader)
                    cout << "Not a valid generator id!!" << endl;
            } while (gid == leader);

            if (crash == leader)
            {
                subLeader = 0;
                for (i = 0; i < n; i++)
                {
                    int index = (i + gid) % n;
                    if (process[index] && subLeader < index)
                    {
                        subLeader = index;
                    }
                    cout << "Election message sent from " << index << " as " << subLeader << endl;
                }

                leader = subLeader;
            }
            display();
            break;

        case 2:
            cout << "Enter Process ID to be activated ";
            cin >> activate;
            if (!process[activate])
                process[activate] = 1;
            else
            {
                cout << "Process " << activate << " is already alive!" << endl;
                break;
            }

            subLeader = activate;
            for (i = 0; i < n; i++)
            {
                int index = (i + activate) % n;
                if (process[index] && subLeader < index)
                {
                    subLeader = index;
                }
                cout << "Election message sent from " << index << " as " << subLeader << endl;
            }

            leader = subLeader;
            display();
            break;

        case 3:
            display();
            break;

        default:
            break;
        }
    } while (schoice != 4);
}