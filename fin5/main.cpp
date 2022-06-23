#include <iostream>

using namespace std;

class MMmanger {
    private:
        int space;
        int* mm;
        int** cp;
    public:
        MMmanger(int size) {
            space = size;
            cp = (int**)malloc(space * sizeof(int*));
            for(int i = 0; i < space; i++) {
                cp[i] = 0;
            }
            mm = (int*)malloc(space * sizeof(int));
        }
        ~MMmanger() {
            free(cp);
            free(mm);
        }
        int get_MMCapacity() {
            int nonsp = 0;
            for(int i = 0; i < space; i++) {
                if(!cp[i]) {
                    nonsp++;
                }
            }
            return nonsp;
        }
        void print_calloc_array(int flag, int size) {
            cout << "Capacity:" << get_MMCapacity() << " - ";
            for(int i = 0; i < space; i++) {
                if(cp[i]) {
                    cout << "1";
                } else {
                    cout << "0";
                }
            }
            if(!get_MMCapacity()) cout << " <- No space";
            if(!flag) cout << " <- Out of space: demand" << size;
            cout << endl;
        }
        int* alloc_MM(int size) {
            int sv = 0, index;
            for(index = 0; index<space; index++ ) {
                if(!cp[index]) {
                    sv++;
                } else {
                    sv = 0;
                }
                if(sv == size) {
                    index -= size - 1;
                    break;
                }
            }
            if(sv < size) {
                print_calloc_array(0, size);
                return NULL;
            }
            for(int i = 0; i < size; i++) {
                cp[index + i] = &mm[index];
            }
            print_calloc_array(1, 0);
            return &mm[index];
        }
        
        
        
        void free_MM(int* p) {
            int i = 0;
            for(i; i< space; i++) {
                if(cp[i] == p) {
                    cp[i] = NULL;
                }
            }
            print_calloc_array(1 ,0);
        }
};
int main() {
    MMmanger mmer(10);
	int* p1 = mmer.alloc_MM(1);
	int* p2 = mmer.alloc_MM(2);
	int* p3 = mmer.alloc_MM(3);
	int* p4 = mmer.alloc_MM(4);
	mmer.free_MM(p1);
    mmer.free_MM(p4);
	int* p5 = mmer.alloc_MM(6);

  return 0;
}
