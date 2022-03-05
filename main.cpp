#include <iostream>
using namespace std;
#include <Windows.h>
#include <MMsystem.h>
#include <vector>
#include <conio.h>

int main() {
    int queue = 0;
    vector<string> tracks;
    tracks.push_back("3_15");
    tracks.push_back("Without Me");
    cout << "< " + tracks[queue] + " >";
    PlaySoundA((tracks[queue] + ".wav").c_str(), NULL, SND_FILENAME | SND_ASYNC);

    while (!_kbhit())
    {
        int value;
        if ((value = _getch()) == 0xE0 || 0) {
            value = _getch();
            if (value == 77) {
                system("CLS");
                if (queue < tracks.size() - 1) {
                    queue++;
                }
                else {
                    queue = 0;
                }
                cout << "< " + tracks[queue] + " >";
                PlaySoundA((tracks[queue] + ".wav").c_str(), NULL, SND_FILENAME | SND_ASYNC);
            }
            if (value == 75) {
                system("CLS");
                if (queue > 0) {
                    queue--;
                }
                else {
                    queue=tracks.size()-1;
                }
                cout << "< " + tracks[queue] + " >";
                PlaySoundA((tracks[queue] + ".wav").c_str(), NULL, SND_FILENAME | SND_ASYNC);
            }
        }
    }

    getchar();

    return 0;
}
