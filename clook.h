#include <iostream> 
#include <algorithm>
#include<math.h>
#include <vector>
using namespace std;
class CLook {
public:
    void cloook(int head, int disksize, int requests[], int seektime, char direction, int size) {
        int totalseektime = 0;
        int totalnumberofheadmovement = 0;
        vector<int> subrequests1;  //subrequests btshel goz2 left bt3 requests 
        vector<int> subrequests2;  //sub requests btshel goz2 el right
        int* sortedrequests = new int[size];


        //bdal ma a3ml left w right h3ml deh w ahot gowa left w right 
            //goz2 shayel left
        for (int i = 0; i < size; i++) {

            if (head >= requests[i]) {
                subrequests1.push_back(requests[i]);

            }
        }

        
       //goz2 shayel l ymen
        for (int i = 0; i < size; i++) {
            if (head < requests[i]) {
                subrequests2.push_back(requests[i]);

            }

            



        }
        if (direction == 'l') {
           
            sort(subrequests1.begin(), subrequests1.end(), greater<int>()); //sorting descending
            sort(subrequests2.begin(), subrequests2.end(), greater<int>());//sorting llgoz2 l tany ascending
        
            // adding both 
            int j = 0;
            for (int i = 0; i < size; i++) {
                if (i < subrequests1.size()) {

                    sortedrequests[i] = subrequests1[i];
                }
                else
                {

                    sortedrequests[i] = subrequests2[j];
                    j++;
                }


            }
            totalnumberofheadmovement += abs(head - sortedrequests[0]);
            
            for (int i = 0; i < size-1; i++) {
                totalnumberofheadmovement += abs (sortedrequests[i] - sortedrequests[i + 1]);
            }

            //totalnumberofheadmovement = (head - subrequests1[subrequests1.size() - 1]) + (subrequests2[subrequests2.size() - 1] - subrequests1[subrequests1.size() - 1]);//distance 

            totalseektime = totalnumberofheadmovement * seektime;//milli second law 3yza bel scond divided 1000
        }
        else if (direction == 'r') {
            sort(subrequests1.begin(), subrequests1.end()); //sorting descending

            sort(subrequests2.begin(), subrequests2.end());//sorting llgoz2 l tany des
           
            int j = 0;
            for (int i = 0; i < size; i++) {
                if (i < subrequests2.size()) {
                    sortedrequests[i] = subrequests2[i];
                }
                else
                {
                    sortedrequests[i] = subrequests1[j];
                    j++;
                }
            }
              totalnumberofheadmovement += abs(head - sortedrequests[0]);
            
            for (int i = 0; i < size-1; i++) {
                totalnumberofheadmovement += abs (sortedrequests[i] - sortedrequests[i + 1]);
            }
           // totalnumberofheadmovement = (subrequests2[subrequests2.size() - 1] - head) + (subrequests2[subrequests2.size() - 1] - subrequests1[subrequests1.size() - 1]);//distance 
            totalseektime = totalnumberofheadmovement * seektime;


        }

        cout << "total number of head movement \t" << totalnumberofheadmovement << endl;

        cout << "total seek time \t" << totalseektime << endl;
        for (int i = 0; i < size; i++)
        {
            cout << sortedrequests[i] << endl;

        }
       system("pause");
    }

};