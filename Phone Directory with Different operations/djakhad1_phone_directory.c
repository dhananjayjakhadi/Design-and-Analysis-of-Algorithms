#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1024
#define MAX 100
//struct
struct contact {
    char firstName[24];
    char lastName[24];
    char phone[24];
}contacts[SIZE], temp;
int length = 0;

// binary search
void binary_search(char *targetFirstName, char *targetLastName, char *targetPhone){
    int bottom= 0;
    int mid;
    int top = length - 1;

    int flag = 0;
    while(bottom <= top) {
        mid = (bottom + top) / 2;
        if(strcmp(contacts[mid].firstName, targetFirstName) == 0 && strcmp(contacts[mid].lastName, targetLastName) == 0) {
            printf("Record Found at: %d\n", mid);
            printf("%s %s, %s\n\n", targetFirstName, targetLastName, targetPhone);
            flag = 1;
            break;
        } else if (strcmp(contacts[mid].firstName, targetFirstName) > 0){
            top = mid - 1;
        } else if (strcmp(contacts[mid].firstName, targetFirstName) < 0){
            bottom = mid + 1;
        }
    }

    if(flag == 1) {
        return;
    } else {
        printf("Name not Found");
    }
    return;
    }

    // delete
    void delete(char *targetFirstName, char *targetLastName, char *targetPhone) {
        int i = 0, j = 0, flag = 0;
        for(i = 0; i < length; i++) {
            if(strcmp(contacts[i].firstName, targetFirstName) == 0 && strcmp(contacts[i].lastName, targetLastName) == 0) {
                flag = 1;
            }
            if(flag == 1) {
                for(j = i; j < (length - 1); j++) {
                    contacts[j] = contacts[j + 1];
                }
                length--;
                break;
            }
        }
    }

    // insert
    void insert(char* name, char* last, char* phone_number) {
        printf("String: %s\n", name);
        int i = 0, j = 0, flag = 0;
        for(i = 0; i < length; i++) {
            if(strcmp(contacts[i].lastName, last) > 0) {
                flag = 1;
            }
            if(flag == 1) {
                int pos = i;
                for(j = length; j > (i - 1); j--) {
                    contacts[j] = contacts[j - 1];
                }
                strcpy(contacts[pos].firstName, name);
                strcpy(contacts[pos].lastName, last);
                strcpy(contacts[pos].phone, phone_number);
                length++;
                break;
            }
        }
    }

    // sorting
    void swap(struct contact *a, struct contact *b)
    {
        struct contact temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
    int partion(int p, int r)
    {
        int pivotIndex = p + rand()%(r - p + 1);
        struct contact pivot;
        int i = p - 1;
        int j;
        pivot = contacts[pivotIndex];
        swap(&contacts[pivotIndex], &contacts[r]);
        for (j = p; j < r; j++)
        {
            if (strcmp(contacts[j].lastName, pivot.lastName) == 0) {
                if(strcmp(contacts[j].firstName, pivot.firstName) == 0) {
                    if(strcmp(contacts[j].phone, pivot.phone) < 0)
                        swap(&contacts[i], &contacts[j]);
                } else if(strcmp(contacts[j].firstName, pivot.firstName) < 0)  {
                    i++;
                    swap(&contacts[i], &contacts[j]);
                }
            } else if (strcmp(contacts[j].lastName, pivot.lastName) < 0){
                i++;
                swap(&contacts[i], &contacts[j]);
            }

        }
        swap(&contacts[i+1], &contacts[r]);
        return i + 1;
    }
    void quick_sort(int p, int q)
    {
        int j;
        if (p < q)
        {
            j = partion(p, q);
            quick_sort(p, j-1);
            quick_sort(j+1, q);
        }
    }

    // function to create file
    void create (char text_file[]) {
        FILE *ptr_file;
        char buf[SIZE];

        ptr_file = fopen(text_file, "ab+");
        if(!ptr_file)
            return;
        int i = 0, innerCount;
        while(fgets(buf, SIZE, ptr_file) != NULL) {
            char * pch;
            pch = strtok (buf," ,.-");
            innerCount = 0;
            while (pch != NULL)
            {
                if(innerCount == 0) {
                    strcpy(contacts[i].firstName,pch);
                } else if(innerCount == 1) {
                    strcpy(contacts[i].lastName, pch);
                } else if(innerCount == 2) {
                    strcpy(contacts[i].phone, pch);
                }
                innerCount++;
                pch = strtok (NULL, " ,.");
            }
            i++;
            length++;

        }
        fclose(ptr_file);
    }

    //print Array
    void printArray() {
        int i = 0;
        for (i = 0; i < length; i++) {
            printf("%s %s, %s", contacts[i].firstName, contacts[i].lastName, contacts[i].phone);
        }
    }

    // main
    int main(int argc, char *argv[]) {
        create(argv[1]);
        char choice;
        char tempFirstName[MAX];
        char tempLastName[MAX];
        char tempPhone[MAX];
        char buf[256];
        char *pch;
        int innerCount = 0;

        while(1) {
            printf("\n1) sort_contact\n2) search\n3) delete\n4) insert\n5) exit\nEnter the Choice: ");
            scanf("%c", &choice);
            while((getchar()!='\n'));
            switch(choice) {
                case '1':
                    quick_sort(0, length - 1);
                    printArray();
                    break;
                case '2':
                    quick_sort(0, length - 1);
                    printf("Enter the Name: ");
                    fgets(buf, 256, stdin);
                    strcpy(tempFirstName, strtok(buf, " ,.-"));
                    strcpy(tempLastName, strtok(NULL, " ,."));
                    strcpy(tempPhone, strtok(NULL, " ,."));
                    binary_search(tempFirstName, tempLastName, tempPhone);
                    printArray();
                    break;
                case '3':
                    quick_sort(0, length - 1);
                    printf("Enter the Name: ");
                    fgets(buf, 256, stdin);
                    strcpy(tempFirstName, strtok(buf, " ,.-"));
                    strcpy(tempLastName, strtok(NULL, " ,."));
                    strcpy(tempPhone, strtok(NULL, " ,."));
                    delete(tempFirstName, tempLastName, tempPhone);
                    printArray();
                    break;
                case '4':
                    quick_sort(0, length - 1);
                    printf("Enter the Name: ");
                    fgets(buf, 256, stdin);
                    strcpy(tempFirstName, strtok(buf, " ,.-"));
                    strcpy(tempLastName, strtok(NULL, " ,."));
                    strcpy(tempPhone, strtok(NULL, " ,."));
                    insert(tempFirstName, tempLastName, tempPhone);
                    printArray();
                    break;
                case '5':
                    exit(1);
                default:
                    exit(1);
            }
        }
        return 0;
    }
