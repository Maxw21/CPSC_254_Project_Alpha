//Rough idea on getting commands and descriptions
#include <iostream>
#include <string.h>

using namespace std;


int main()
{
    Node *current = new Node; //Import linked list
    current = head;
    
    while (current != NULL)
    {
        if (current -> address == "40000810")
        {
            switch (current -> data)
            {
                case "00000000":
                    cout << current -> lineNumber << ": " << current -> cycle << " S-to-D command: 0 words";
                    current = current -> next;
                    break;
                
                case "0000000C":
                    cout << current -> lineNumber << ": " << current -> cycle << " S-to-D command: 6 words";
                    current = current -> next;
                    break;
                    
                case "00000018":
                    cout << current -> lineNumber << ": " << current -> cycle << " S-to-D command: 12 words";
                    current = current -> next;
                    break;
            }
        }
        else if (current -> address == "40000C18")
        {
            switch (current -> data)
            {
                case "00000000":
                    cout << current -> lineNumber << ": " << current -> cycle << " D-to-S command: 0 words";
                    current = current -> next;
                    break;
                    
                case "00000054":
                    cout << current -> lineNumber << ": " << current -> cycle << " D-to-S command: 42 words";
                    current = current -> next;
                    break;
            }
        }
        else
        {
            if (current -> address >= "40000818" && current -> address <= "4000086B")
            {
                //1. Use hexadecimal to binary converter, put binary into array if not already done so
                //2. Determine word # to find field name and descripton
                //3. Maybe use nested switch statements to get field name and description
                //ex. switch (wordNumber)
                //    {
                //          case 0:
                //              int description = bit[14] + bit[13];
                //              switch (description)
                //              {
                //                  case 0:
                //                      cout << "Word " <<  wordNumber << ": Rec_Ctrl = 0 (no recording)";
                //                      break;
                //
                //                  case 2:
                //                      cout << "Word " << wordNumber << ": Rec_Ctrl = 2 (no processing)";
                //                      break;
                //
                //                  etc ...
                //
                //          case 1:
                //              int description = bit[15]+bit[14]+bit[13];
                //              switch (description)
                //              {
                //                  case 4:
                //                      cout << "Word " << wordNumber << ": Cmd_Type = 4 (A)";
                //                      break;
                //
                //                  case 5:
                //                      cout << "Word " << wordNumber << ": Cmd_Type = 5 (B)";
                //                      break;
                //
                //                  etc ...
                //              }
                //
                //          case 4:
                //              description = bit[0];
                //              switch (description)
                //              {
                //                  case 0:
                //                      cout << "Word " << wordNumber << "Rec_Raw = 0 (disable)";
                //                      break;
                //
                //                  case 1:
                //                      cout << "Word " << wordNumber << "Rec_Raw = 1 (enable)";
                //                      break;
                //
                //                  etc ...
                //              }
                //
                //          case ...
                //
                //          case 41:
                //              etc ...
                //
                //
                //    }
            }
            else if (current -> address >= "40000C20" && current -> address <= "40000C73")
            {
                // slightly same implementation as above
            }
        }
    }
    
    return 0;
}


