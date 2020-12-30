#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;
class sstf {
    void SSTF(int requests[], int head_position, int req_count, int seek_count, int disk_size) {
        cout << "SSTF: " << endl;

        int* requests_x = new int[req_count];
        for (int i = 0; i < req_count; i++) {
            requests_x[i] = requests[i];
        }

        int* sstf_requests = new int[req_count];
        for (int i = 0; i < req_count; i++) {
            sstf_requests[i] = requests_x[i];
        }
        int current_request = head_position;
        int current_request_index = -1;
        int least_distance = 99999;
        int least_distance_index = 0;
        for (int i = 0; i < req_count; i++) {
            for (int j = 0; j < req_count; j++) {
                if (j == current_request_index) {
                    continue;
                }
                if (least_distance > abs(current_request - requests_x[j])) {
                    least_distance = abs(current_request - requests_x[j]);
                    least_distance_index = j;
                }
            }
            least_distance = 99999;
            sstf_requests[i] = requests_x[least_distance_index];
            current_request = requests_x[least_distance_index];
            requests_x[least_distance_index] = 99999;
        }

        cout << "Order: " << head_position << " -> ";
        string _ = " -> ";

        for (int i = 0; i < req_count; i++) {
            string arrow = " -> ";
            if (i == req_count - 1) {
                arrow = "";
            }
            cout << sstf_requests[i] << arrow;
        }

        int total_distance = abs(head_position - sstf_requests[0]);
        for (int i = 0; i < req_count - 1; i++) {
            total_distance += abs(sstf_requests[i] - sstf_requests[i + 1]);
        }
        cout << "\n" << "Seek: " << total_distance << " cylinders, " << total_distance * seek_count << "ms";
        cout << endl << endl;
    }
};
