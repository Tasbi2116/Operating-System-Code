#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int page_size, frame_size, page_table[100], page_number, frame_number, offset, logical_address, physical_address;
    int i = 0, j = 0;
    int lms, pms;

    cout << "Logical Memory size: " ;
    cin >> lms;

    cout << "Physical Memory size: ";
    cin >> pms;

    cout << "Enter the page size: ";
    cin >> page_size;

    cout << "Enter the frame size: ";
    cin >> frame_size;

    int num_pages = lms/page_size;
    int num_frames = pms/frame_size;

    cout << endl << "Number of pages : " << num_pages <<endl;
    cout << endl << "Number of frame : " << num_frames <<endl;

    //int num_pages = pow(2, page_size);
   // int num_pages = page_size;
   // int num_frames = 2* frame_size;

    cout << "\nEnter the page table:\n\n";
    cout << "Page number\tFrame number\n";

    for (i = 0; i < num_pages; i++) {
        cout << i << "\t\t";
        cin >> page_table[i];
    }

    cout << "\nEnter the logical address: ";
    cin >> logical_address;

    if (logical_address < num_pages) {
        page_number = logical_address / frame_size;
        offset = logical_address % frame_size;
        frame_number = page_table[page_number];
        physical_address = (frame_number * frame_size) + offset;
        cout << "\nThe intended physical address = " << physical_address;
    } else {
        cout << "Logical address does not exist!";
    }

    return 0;
}