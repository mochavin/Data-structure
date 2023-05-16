#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define all(x) x.begin(), x.end()
#define endl '\n'

vector<string> parent;

struct Directory {
    string name;
    map<string, Directory*> subdirs;
    vector<string> files;
};

void mkdir(Directory* root, string path) {
    vector<string> dirs;
    string dir = "";
    path = path.substr(9);
    for (int i = 0; i < path.length(); i++) {
        if (path[i] == '/') {
            dirs.push_back(dir);
            dir = "";
        }
        else {
            dir += path[i];
        }
    }
    auto itParent = find(all(parent), dirs[0]);
    if(itParent == parent.end())
      parent.push_back(dirs[0]);
    dirs.push_back(dir);
    Directory* curr = root;
    for (int i = 0; i < dirs.size(); i++) {
        if (curr->subdirs.find(dirs[i]) == curr->subdirs.end()) {
            Directory* new_dir = new Directory{dirs[i]};
            curr->subdirs[dirs[i]] = new_dir;
            curr = new_dir;
            curr->name = dirs[i];
        }
        else {
            curr = curr->subdirs[dirs[i]];
        }
        if(i < dirs.size()-1){
          auto it = find(all(curr->files), dirs[i+1]);
          if(it == curr->files.end())
            curr->files.push_back(dirs[i+1]);
        }
    }
}

void ls(Directory* root, string path) {
    Directory* curr = root;
    vector<string> dirs;
    string dir = "";
    path = path.substr(3);
    for (int i = 0; i < path.length()-1; i++) {
        if (path[i] == '/') {
            dirs.push_back(dir);
            dir = "";
        }
        else {
            dir += path[i];
        }
    }
    dirs.push_back(dir);

    for (int i = 0; i < dirs.size(); i++) {
        if (curr->subdirs.find(dirs[i]) == curr->subdirs.end()) {
            cout << "ls: " << dirs[i] << ": No such file or directory" << endl;
            return;
        }
        else {
            curr = curr->subdirs[dirs[i]];
        }
    }
    // if(curr->subdirs[dirs[dirs.size()-1]] == nullptr){
    //   cout << "ls: " << dirs[dirs.size()-1] << ": No such file or directory" << endl;
    //   return;
    // }
    // curr = curr->subdirs[dirs[dirs.size()-1]];

    for(int i = 0; i < curr->files.size(); i++)
      cout << curr->files[i] << " ";
    cout << endl;
}


int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n;
    cin >> n;

    Directory* root = new Directory{""};
    cin.ignore();
    while (n--) {
        string path;
        getline(cin, path);
        if (path.substr(0, 8) == "mkdir -p") {
            mkdir(root, path);
        }
        else if (path.substr(0,2) == "ls") {
            ls(root, path);
        }else{
          cout << "command not found: " << path << endl;
        }
    }
    return 0;
}

/*
10
mkdir -p lol/haha/aku/suka/nasi/goreng/rasa/ayam/
mkdir -p lol/haha/aku/dia/
mkdir -p lol/haha/aku/kamu/
mkdir -p lol/haha/aku/ore/botol/
ls lol/
ls lol/haha/aku/suka/nasi/goreng/rasa/
ls lol/haha/aku/
ls lol/haha/aku/ore/
ls lol/haha/aku/suka/nasi/goreng/rasa/
tree
*/