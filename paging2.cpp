#include <iostream>
#include <vector>

using namespace std;

int main() {
    int logical_memory_size, physical_memory_size, page_size, frame_size, logical_address, physical_address;

    cout << "Logical Memory size: ";
    cin >> logical_memory_size;

    cout << "Physical Memory size: ";
    cin >> physical_memory_size;

    cout << "Enter the page size: ";
    cin >> page_size;

    cout << "Enter the frame size: ";
    cin >> frame_size;

    int num_pages = logical_memory_size / page_size;
    int num_frames = physical_memory_size / frame_size;

    cout << "\nNumber of pages: " << num_pages << endl;
    cout << "Number of frames: " << num_frames << endl;

    vector<int> page_table(num_pages);

    cout << "\nEnter the page table:\n";
    for (int i = 0; i < num_pages; i++) {
        cout << "Page " << i << " -> Frame: ";
        cin >> page_table[i];
    }

    cout << "\nEnter the logical address: ";
    cin >> logical_address;

    if (logical_address < logical_memory_size) {
        int page_number = logical_address / page_size;
        int offset = logical_address % page_size;

        if (page_number < num_pages) {
            int frame_number = page_table[page_number];
            physical_address = (frame_number * frame_size) + offset;

            cout << "\nPage Number: " << page_number << endl;
            cout << "Offset: " << offset << endl;
            cout << "Frame Number: " << frame_number << endl;
            cout << "Physical Address: " << physical_address << endl;
        } else {
            cout << "Page not found in the page table!" << endl;
        }
    } else {
        cout << "Logical address is out of range!" << endl;
    }

    return 0;
}
