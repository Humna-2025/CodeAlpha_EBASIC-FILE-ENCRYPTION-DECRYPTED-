# CodeAlpha_EBASIC-FILE-ENCRYPTION-DECRYPTED

🔷 Overview
=
This program reads a text file, encrypts or decrypts its content using a simple Caesar cipher (shifting each character by a key value), and writes the result to another file.

It supports two operations:
✅ Encrypt a file

✅ Decrypt a file

🔷 Class: FileEncryptor
=
The main class encapsulates all logic.

🔹 Private Member
=
Holds the shift amount for encryption/decryption (default = 3).

🔹 Constructor
=
Initializes the key. Defaults to 3 if no value is passed.

🔹 Encryption Method
=
Loops over each character in the input text and shifts its ASCII value upward by key.

🔹 Decryption Method
=
Reverses the encryption by shifting downward by key.

🔹 File Processing Method
=
This method:
✅ Opens the inputFile for reading.

✅ Opens the outputFile for writing.

✅ Reads line-by-line from the input, encrypts or decrypts each line, and writes it to the output.

✅ Displays a success message when done.

📄 Main Function
=
🔷 Presents a menu:

1 = Encrypt a file

2 = Decrypt a file

🔷 Asks user to enter:

Input file name

Output file name

🔷 Calls processFile() with encryptMode flag set appropriately.

🔷 Sample Run
=
--- File Encryptor/Decryptor ---

1. Encrypt a file
   
2. Decrypt a file
3. 
Enter choice: 1

Enter input file name: INPUT FILE.txt

Enter output file name: OUTPUT FILE.txt

Encryption completed. Saved to 'OUTPUT FILE.txt'.

🔷 Improvements Suggested
=
✅ Replace hardcoded file paths inside processFile() with inputFile and outputFile parameters:

ifstream inFile(inputFile);

ofstream outFile(outputFile);

✅ Fix file-open checking (as shown above).

✅ Optionally allow the user to enter a custom key.


code
=


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
                                         
                                          
  OUTPUT
  =
                                            --- File Encryptor/Decryptor ---
                                            1. Encrypt a file
                                            2. Decrypt a file
                                            Enter choice: 1
                                            Enter input file name: INPUT FILE.txt
                                            Enter output file name: OUTPUT FILE.txt
                                            Encryption completed. Saved to 'OUTPUT FILE.txt'



                                            
