#include <iostream>
using namespace std;

#define MAX 20

int process[MAX], n, leader;
void bully();
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
        cout << "\n1.BULLY Algorithm \t2.RING Algorithm \t3.DISPLAY \t4.EXIT\n";
        cout << "Enter your choice : ";
        cin >> fchoice;
        switch (fchoice)
        {
        case 1:
            bully();
            break;

        case 2:
            ring();
            break;

        case 3:
            display();
            break;

        case 4:
            break;

        default:
            break;
        }
    } while (fchoice != 4);

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

void bully()
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
                {
                    // Becoz the leader itself starts election makes "no sense"
                    // & if leader is dead then also it cannot start the election itself.
                    cout << "Not a valid generator id!!" << endl;
                }

            } while (gid == leader);
            flag = 0;

            if (crash == leader)
            {
                for (i = gid + 1; i < n; i++)
                {
                    cout << "Message is sent from " << gid << " to " << i << endl;
                    if (process[i])
                    {
                        subLeader = i;
                        cout << "Response is sent from " << i << " to " << gid << endl;
                        flag = 1;
                    }
                }

                if (flag == 1)
                    leader = subLeader;
                else
                    leader = gid;
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

            flag = 0;

            for (i = activate + 1; i < n; i++)
            {
                cout << "Message is sent from " << activate << " to " << i << endl;
                if (process[i])
                {
                    subLeader = i;
                    cout << "Response is sent from " << i << " to " << activate;
                    flag = 1;
                }
            }

            if (flag == 1)
                leader = subLeader;
            else
                leader = activate;
            display();
            break;

        case 3:
            display();
            break;

        case 4:
            break;
        }
    } while (schoice != 4);
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