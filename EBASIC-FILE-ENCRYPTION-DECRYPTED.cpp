#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileEncryptor {
private:
 int key; // Shift value

public:
 FileEncryptor(int k = 3) {
 key = k;
 }

 string encrypt(string text) {
 for (int i = 0; i < text.length(); i++) {
 text[i] = text[i] + key;
 }
 return text;
 }

 string decrypt(string text) {
 for (int i = 0; i < text.length(); i++) {
 text[i] = text[i] - key;
 }
 return text;
 }

 void processFile(string inputFile, string outputFile, bool encryptMode) {
 ifstream inFile("E:\\INTERSHIP PROJECT\\INTERSHIP-3MONTH\\TASK-2\\INPUT FILE.txt");
 ofstream outFile("E:\\INTERSHIP PROJECT\\INTERSHIP-3MONTH\\TASK-2\\OUTPUT FILE.txt");
 string line;

 if (!"E:\\INTERSHIP PROJECT\\INTERSHIP-3MONTH\\TASK-2\\INPUT FILE.txt" || !"E:\\INTERSHIP PROJECT\\INTERSHIP-3MONTH\\TASK-2\\OUTPUT FILE.txt") {
 cout << "Error opening files.\n";
 return;
 }

 while (getline(inFile, line)) {
 string processedLine;

 if (encryptMode) {
 processedLine = encrypt(line);
 } else {
 processedLine = decrypt(line);
 }

 outFile << processedLine << endl;
 }

 inFile.close();
 outFile.close();

 if (encryptMode) {
 cout << "Encryption completed. Saved to '" << outputFile << "'.\n";
 } else {
 cout << "Decryption completed. Saved to '" << outputFile << "'.\n";
 }
 }
};

int main() {
 FileEncryptor encryptor;
 string inputFile, outputFile;
 int choice;

 cout << "--- File Encryptor/Decryptor ---\n";
 cout << "1. Encrypt a file\n";
 cout << "2. Decrypt a file\n";
 cout << "Enter choice: ";
 cin >> choice;

 cout << "Enter input file name: ";
 cin >> inputFile;

 cout << "Enter output file name: ";
 cin >> outputFile;

 if (choice == 1) {
 encryptor.processFile(inputFile, outputFile, true);
 } else if (choice == 2) {
 encryptor.processFile(inputFile, outputFile, false);
 } else {
 cout << "Invalid choice.\n";
 }

 return 0;
}
