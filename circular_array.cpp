#include <iostream>
using namespace std;

int next_normalized_index(int index, int size){
    int result = ((index % size) + size) % size;
    return result;
}


int main(){
    const int size = 5;
    int circular_array[size] = {1,-1,5,1,4};
    /* when you declare a standard array on the stack the compiler must know exactly how much memory to 
    allocate for that array at compile time, since a regular int can change during runetime the compiler 
    can't predict it's value during compilation */ 
    int seen_nodes[size] = {0}; 

    bool isCycle = false;

    // traverse circular array
    for(int i = 0; i < size; i++){
        if(seen_nodes[i] == 1) continue;

        int current = i;
        bool isPositive = current >= 0;
        bool seqInvalid = false;
        // cout << current << endl;
        int size = 0;
        while(!seen_nodes[current]){
            seen_nodes[current] = 1;

            int next_idx = next_normalized_index(current + circular_array[current], 5);
            bool same_sign = !(isPositive ^ (circular_array[next_idx] >= 0));
            if(!same_sign) seqInvalid = true;
            
            current = next_idx;
            size++;
        }
        if(current == i || seen_nodes && !seqInvalid && size > 1){
            // found a cycle
            isCycle = true;
            cout << "cycle starts and ends at: " << current << "\n";
        }
    }
    cout << endl;


}

