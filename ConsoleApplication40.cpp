#include <iostream> 
#include <algorithm>
#include <vector>
#include "FCFS.h"
#include "Scan.h"
#include "look.h"
#include "clook.h"
using namespace std;



int main()
{
    int x;
    cout << "enter 1 for FCFS " << endl;
    cout << "enter 2 for SCAN" << endl;
    cout << "enter 3 for look" << endl;
    cout << "enter 4 for clook" << endl;
    cin >> x;
    int disksize;
    cout << "Please write the disk size:\t";
    cin >> disksize;

    if (x == 1) {
        int head;
        cout << "Please write the head:\t" << endl;
        cin >> head;
        cout << "enter the size number" << endl;
        int sizenum;
        cin >> sizenum;
        int* arr = new int[sizenum];
        cout << "enter the requests" << endl;
        int temp = 0;
        for (int i = 0; i < sizenum; i++) {
            cin >> temp;
            if (temp > disksize) {
                cout << "The request are bigger than disk size. Please enter again" << endl;
                i--;
            }
            else { arr[i] = temp; }

        }
        FCFSc myobject;

      myobject.FCFS(arr, head, sizenum);
    }
    else if (x == 2) {

        char direction;
        cout << "enter direction , l for left , r for right:\t ";
        cin >> direction;
        int head;
        cout << "Please write the head:\t";
        cin >> head;

        int requestcount;//heya heya size num
        cout << "enter number of requests:\t";
        cin >> requestcount;
        int* requests = new int[requestcount];
        cout << "Please enter the requests you want:\t";
        int temp = 0;
        for (int i = 0; i < requestcount; i++) {
            cin >> temp;
            if (temp > disksize) {
                cout << "The request are bigger than disk size. Please enter again" << endl;
                i--;
            }
            else { requests[i] = temp; }
        }
        int seektime;
        cout << "please write the seek time:\t";
        cin >> seektime;

        Scan myobj;
       myobj.SCAN(head, disksize, requests, seektime, direction, requestcount);
    }

    else if (x == 3) {
        int  n = 0, head;
        char direction;
        cout << "enter direction , l for left , r for right:\t ";
        cin >> direction;
        int* requests = new int[n];
        cout << "Enter the head position\n";
        cin >> head;
        cout << "Enter number of requests\n";
        cin >> n;
        int seektime;
        cout << "please write the seek time:\t";
        cin >> seektime;

        cout << "Enter the requests\n";
        int temp = 0;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            if (temp > disksize) {
                cout << "The request are bigger than disk size. Please enter again" << endl;
                i--;
            }
            else { requests[i] = temp; }
        }
        Look myobj;
        myobj.look(head, disksize, requests, seektime, direction, n);
    }
    else if (x == 4) {
        int  n = 0, head;
        char direction;
        cout << "enter direction , l for left , r for right:\t ";
        cin >> direction;
        int* requestss = new int[n];
        cout << "Enter the head position\n";
        cin >> head;
        cout << "Enter number of requests\n";
        cin >> n;
        int seektime;
        cout << "please write the seek time:\t";
        cin >> seektime;

        cout << "Enter the requests\n";
        int temp = 0;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            if (temp > disksize) {
                cout << "The request are bigger than disk size. Please enter again" << endl;
                i--;
            }
            else { requestss[i] = temp; }
        }
        CLook myobj;
        myobj.cloook( head,  disksize,  requestss, seektime,  direction,  n);


        return 0;
    }
}