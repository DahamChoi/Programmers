#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct file {
    string head, number_str, tail;
};

vector<string> solution(vector<string> files) {
    vector<string> answer;

    vector<file> file_list;

    for (int i = 0; i < files.size(); i++) {
        for (int k = 0; k < files[i].length(); k++) {
            file f;
            if (files[i][k] >= '0' && files[i][k] <= '9') {
                f.head = files[i].substr(0, k);
                int j = k;
                while (files[i][j] >= '0' && files[i][j] <= '9') {
                    ++j;
                }
                f.number_str = files[i].substr(k, j - k).c_str();
                f.tail = files[i].substr(j, files[i].length() - j);
                file_list.push_back(f);
                break;
            }
        }
    }

    sort(file_list.begin(), file_list.end(), [](const file& f1, const file& f2) {
        string head_1 = f1.head;
        string head_2 = f2.head;

        transform(head_1.begin(), head_1.end(), head_1.begin(), [](unsigned char c) {
            return tolower(c);
            });
        transform(head_2.begin(), head_2.end(), head_2.begin(), [](unsigned char c) {
            return tolower(c);
            });

        if (head_1 == head_2) {
            int num_1 = atoi(f1.number_str.c_str());
            int num_2 = atoi(f2.number_str.c_str());
            if (num_1 == num_2) {
                return false;
            }

            return num_1 < num_2;
        }

        return head_1 < head_2;
        });

    for (int i = 0; i < file_list.size(); i++) {
        answer.push_back(file_list[i].head + file_list[i].number_str +file_list[i].tail);
    }

    return answer;
}

int main()
{
    solution({ "img0100.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" });
}