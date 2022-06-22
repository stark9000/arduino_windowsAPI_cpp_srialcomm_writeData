#include "SerialClass.h" // Library described above
int CHOICE;

char *msg = strdup("0");
int msgLen = 0;
bool writeSuccess = false;

// application reads from the specified serial port and reports the collected data
int main()
{
    printf("Welcome to the serial test app!\n\n");

    Serial *SP = new Serial("\\\\.\\COM13"); // adjust as needed

    if (SP->IsConnected())
        cout << "We're connected";
    cout << "\n";

    while (SP->IsConnected())
    {

        do
        {
            printf("Enter 1 to turn on the LED");
            printf("\n");
            printf("Enter 0 to turn off the LED");
            printf("\n");
            printf("any other char to quit");
            printf("\n");
            cin >> CHOICE;
            printf("\n");

            printf("CHOICE = %d", CHOICE);
            printf("\n");

            if (CHOICE == 1)
            {
                printf("turning on LED");
                printf("\n");
                msg = strdup("1");
                msgLen = strlen(msg);
                writeSuccess = SP->WriteData(msg, msgLen);
            }
            else if (CHOICE == 0)
            {
                printf("turning off LED");
                printf("\n");
                msg = strdup("0");
                msgLen = strlen(msg);
                writeSuccess = SP->WriteData(msg, msgLen);
            }
            else
            {
                cout << "exit !";
                exit(0);
            }
        } while (1);

        Sleep(500);
    }
    return 0;
}