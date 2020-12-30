#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;
class FCFSc {
 public:
     void FCFS(int req[], int head, int sizenum)
     {

         int seek_counter = 0;
         int distance, cur_num; 


         for (int i = 0; i < sizenum; i++) {
             cur_num = req[i];

             distance = abs(cur_num - head);

             seek_counter += distance;

             head = cur_num;
         }

         cout << "Total number of seek operations = "
             << seek_counter << endl;


         cout << "Seek Sequence is" << endl;

         for (int i = 0; i < sizenum; i++) {
             cout << req[i] << endl;
         }
     }
};
