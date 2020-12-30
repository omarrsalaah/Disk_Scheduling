#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;
class Scan {
public:

void SCAN(int head, int disksize, int requests[], int seektime, char direction, int size) {
    int totalseektime = 0;
    int totalnumberofheadmovement;
    vector<int> subrequests1;  //subrequests btshel goz2 left bt3 requests 
    vector<int> subrequests2;  //sub requests btshel goz2 el right
    int* sortedrequests = new int[size];


    //bdal ma a3ml left w right h3ml deh w ahot gowa left w right 
        //goz2 shayel left
    for (int i = 0; i < size; i++)

        if (head >= requests[i]) {
            subrequests1.push_back(requests[i]);

        }

    sort(subrequests1.begin(), subrequests1.end(), greater<int>()); //sorting descending
   //goz2 shayel l ymen
    for (int i = 0; i < size; i++) {
        if (head < requests[i]) {
            subrequests2.push_back(requests[i]);

        }

        sort(subrequests2.begin(), subrequests2.end());//sorting llgoz2 l tany ascending



    }
    if (direction == 'l') {
        // adding both 
        int j = 0;
        subrequests1.push_back(0);
        for (int i = 0; i <= size; i++) {
            if (i < subrequests1.size()) {

                sortedrequests[i] = subrequests1[i];
            }
            else
            {

                sortedrequests[i] = subrequests2[j];
                j++;
            }


        }

        totalnumberofheadmovement = head + sortedrequests[size - 1];//distance 

        totalseektime = totalnumberofheadmovement * seektime;//milli second law 3yza bel scond divided 1000
    }
    else if (direction == 'r') {
        int j = 0;
        subrequests2.push_back(disksize - 1);
        for (int i = 0; i <= size; i++) {
            if (i < subrequests2.size()) {
                sortedrequests[i] = subrequests2[i];
            }
            else
            {
                sortedrequests[i] = subrequests1[j];
                j++;
            }
        }
        totalnumberofheadmovement = (disksize - head - 1) + (disksize - 1 - sortedrequests[size - 1]);//distance 
        totalseektime = totalnumberofheadmovement * seektime;


    }

    cout << "total number of head movement \t" << totalnumberofheadmovement << endl;

    cout << "total seek time \t" << totalseektime << endl;
    for (int i = 0; i <= size; i++)
    {
        cout << sortedrequests[i] << endl;

    }
}
};