#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fptr;
    //searches for this string in a txt file
    char searchforthis[200];

    //file name to display at output
    char ch, file_name[200];
    FILE *fp;

    for (int i = 0; i < 5; i++) /* this will execute 5 times */
        {
        //Asks for full directory of txt file (example: C:\users\...) and reads that file.
        //fp is content of file
        printf("Enter name of a file you wish to check:\n");
        gets(file_name);

        fp = fopen(file_name, "r"); // read mode

        //If there's no data inside the file it displays following error message
        if (fp == NULL)
        {
            perror("Error while opening the file.\n");
            exit(EXIT_FAILURE);
        }



        char* p;
        char buff[500];
        int flag = 0, lines = 1;
        //asks for string (what has to be searched)
        printf("Enter what you want to search: \n");
        scanf("%1s", searchforthis); /* 199 characters + \0 to mark the end of the string */

        if (scanf("%199s", searchforthis) != 1)
        {
            exit(EXIT_FAILURE);
        }

            while (fgets(buff, sizeof(buff), fp) != NULL)
        {

            size_t len = strlen(buff); /* get the length of the string */

            if (len > 0 && buff[len - 1] == '\n') /* check if the last character is the newline character */
                {
                buff[len - 1] = '\0'; /* place \0 in the place of \n */
                }

                // Find first occurrence of searchforthis in fp
                p = strstr(searchforthis, buff);

            if (p != NULL)
            {
                /* match - set flag to 1 */
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            printf("This Value has not been found.\n");
        }
        else
        {
            printf("This Value was found in following file:\n%s", file_name);
        }

        fclose(fp);
        return 0;
        }
}
