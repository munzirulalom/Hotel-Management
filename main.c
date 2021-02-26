#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>

char username[50];
int item_id=0;

struct admin
{
    char name[100];
    char username[50];
    char password[100];
    char email[50];
    char nationality[20];
} admin_nfo;
struct user
{
    char name[100];
    char username[50];
    char email[50];
    char password[100];
    char nid[50];
    char address[100];
    char nationality[20];
} user_info;
struct employee
{
    int id;
    char name[100];
    char address[100];
    long salary;
} employee_info;
struct room
{
    int no;
    char name[50];
    char features[200];
    int type;
    int price;
    int status;
} room_info;
struct food
{
    int code;
    char name[50];
    char description[200];
    int price;
    int category;
    int status;
} food_info;
struct order
{
    int or_id;
    char or_name[100];
    char or_type[50];
    char or_user[100];
    char or_payment[10];
    int or_status;
    long int or_price;
    int item_id;
    char in_date[25];
    char out_date[25];
    int item_count;
    int adult_count;
    int children_count;
} order_info;
struct payment
{
    int no;
    int code;
    char expire;
} payment_info;

//All Function
void login();
void registration();
void main_menu();
void employee_menu();
void room_menu();
void food_menu();

void add_room();
void room_list();
void update_room();
void delete_room();
void room_search();

void add_food();
void food_list();
void update_food();
void delete_food();
void food_search();

void add_employee();
void employee_list();
void update_employee();
void delete_employee();
void employee_search();

void order_search();
void order_room();
void order_details();
void order_food();
void user_order_history();
void update_order_status();

void payment();
void card();
void m_banking();

void thanks();
void update_order();
void order_room_update();

/*
    ==================================================================================
                                Contact Function
    ==================================================================================
*/
void contact()
{
    system("CLS");
    printf("\n\n\n");
    printf("\t\t\t::::: Hotel Management System :::::\n\n");
    printf("\t\tName: D.M. Ajmain Shariar\tID: 19202103308\t\tEmail: ajmainshariar77@gmail.com\n");
    printf("\t\tName: MD Mahabub Morshed\tID: 19202103298\t\tEmail: mdmahabubmorshed876@gmail.com\n");
    printf("\t\tName: Munzirul Alom\t\tID: 19202103303\t\tEmail: cse.alomb008@gmail.com\n");

    getch();
    main_menu(1);
}

/*
    ==================================================================================
                                Registration Function
    ==================================================================================
*/
void registration(int n)
{
    if(n==1)
    {
        n=0;
        FILE *reg;
        reg = fopen("admin.txt", "ab+");

        printf("Enter username: ");scanf("%s", &admin_nfo.username);
        printf("Enter your name: ");scanf("%s", &admin_nfo.name);
        printf("Enter your email: ");scanf("%s", &admin_nfo.email);
        printf("Enter a password: ");scanf("%s", &admin_nfo.password);
        printf("Enter your nationality: ");scanf("%s", &admin_nfo.nationality);

        fwrite(&admin_nfo, sizeof(admin_nfo), 1, reg);
        fclose(reg);

        printf("\nRegistration Successful\n\n");
        printf("Press any key to Login...");
        getch();
        system("cls");
        login(1);
    }
    else if (n == 2)
    {
        n=0;
        FILE *reg;
        reg = fopen("user.txt", "ab+");

        printf("Enter username: ");scanf("%s", &user_info.username);
        printf("Enter your name: ");scanf("%s", &user_info.name);
        printf("Enter your email: ");scanf("%s", &user_info.email);
        printf("Enter a password: ");scanf("%s", &user_info.password);
        printf("Enter your NID/Passport no: ");scanf("%s", &user_info.nid);
        printf("Enter your address: ");scanf("%s", &user_info.address);
        printf("Enter your nationality: ");scanf("%s", &user_info.nationality);

        fwrite(&user_info, sizeof(user_info), 1, reg);
        fclose(reg);

        printf("\nRegistration Successful\n\n");
        printf("Press any key to Login...");
        getch();
        system("cls");
        login(2);
    }
}

/*
    ==================================================================================
                                Login Function
    ==================================================================================
*/
void login(int n)
{
    char password[100];
    int flag;
    FILE *log;

    if(n==1) //Admin Login
    {
        flag=0;
        log = fopen("admin.txt", "rb");

        if (log == NULL)
        {
            printf("Error: Unable to open file.\n");
            exit(1);
        }

        printf("Username: ");scanf("%s", &username);
        printf("Password: ");scanf("%s", &password);

        while(fread(&admin_nfo, sizeof(admin_nfo), 1, log) && flag==0)
        {
            if(strcmp(username,admin_nfo.username)==0 && strcmp(password,admin_nfo.password) == 0)
            {
                flag=1;
                printf("\nAdmin Login Successful\n\n");
            }
            else
            {
                printf("Incorrect Username or Password. Please Try again\nPress any key to try again...");
                getch();
                system("cls");
                login(1);
            }
        }
        fclose(log);
        if(flag==1)
            main_menu(1);
    }
    else if(n==2) //User Login
    {
        flag=0;
        log = fopen("user.txt", "rb");

        if (log == NULL)
        {
            printf("Error: Unable to open file.\n");
            exit(1);
        }

        printf("Username: ");scanf("%s", &username);
        printf("Password: ");scanf("%s", &password);

        while(fread(&user_info, sizeof(user_info), 1, log) && flag==0)
        {
            if(strcmp(username,user_info.username)==0 && strcmp(password,user_info.password) == 0)
            {
                flag=1;
                printf("\nUser Login Successful\n\n");
            }
            else
            {
                printf("Incorrect Username or Password. Please Try again\nPress any key to try again...");
                getch();
                system("cls");
                login(2);
            }
        }
        fclose(log);

        if(flag==1)
            main_menu(2);
    }

}

/*
    ==================================================================================
                                    Main Function
    ==================================================================================
*/
int main()
{
    int n;

    int x; double y;
    char text1[]=    "\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n\t\t\t::                                         ::\n\t\t\t::                                         ::\n\t\t\t:::::::::: Hotel Management System ::::::::::\n\t\t\t::                                         ::\n\t\t\t::                                         ::\n\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n\n\n";
    char text2[]=    "\t\t\t\t1. Admin System\n\t\t\t\t2. User System\n\n";
    char text3[]=    "\t\t\t\tEnter your choice: ";
    printf("\n\n");
    for(x=0; text1[x]!=NULL; x++)
    {
        printf("%c",text1[x]);
        for(y=0; y<=1111111; y++)
        {
        }
    }
    printf("\n\n");
    for(x=0; text2[x]!=NULL; x++)
    {
        printf("%c",text2[x]);
        for(y=0; y<=4444444; y++)
        {
        }
    }
    printf("\n\n");
    for(x=0; text3[x]!=NULL; x++)
    {
        printf("%c",text3[x]);
        for(y=0; y<=9999999; y++)
        {
        }
    }
    scanf("%d", &n);

    system("cls");
    if(n==1) //Admin Login and Registration
    {
        n=0;
        printf("1. Login\n");
        printf("2. Registration\n");
        printf("Enter choice: ");scanf("%d", &n);
        system("cls");
        if(n==1)
            login(1);
        else if(n==2)
            registration(1);
        else
            printf("Error: Invalid input");
    }
    else if(n==2) //User Login and Registration
    {
        n=0;
        printf("1. Login\n");
        printf("2. Registration\n");
        printf("Enter choice: ");scanf("%d", &n);
        system("cls");
        if(n==1)
            login(2);
        else if(n==2)
            registration(2);
        else
            printf("Error: Invalid input");
    }
    else
        printf("Error: Invalid input");

    return 0;
}

/*
    ==================================================================================
                                Main Menu Function
    ==================================================================================
*/
void main_menu(int n)
{
    system("cls");

    if(n==1) //Admin Main Menu
    {
        n=0;
        int m;
        printf("::::::::::Admin Menu::::::::::\n\n");
        printf("1. Hotel Name\n");
        printf("2. Hotel Features\n");
        printf("3. Location\n");
        printf("4. Checkout\n");
        printf("5. Order\n");
        printf("6. Room\n");
        printf("7. Food\n");
        printf("8. Employee\n");
        printf("9. User\n");
        printf("10. Payment\n");
        printf("11. Contact\n");
        printf("12. Logout\n\n");
        printf("Enter Choice: ");scanf("%d", &m);

        switch(m)
        {
        case 1:
            printf("Hotel Name Function");
            getch();
            main_menu(1);
            break;
        case 2:
            system("cls");
            //hotel_features();
            break;
        case 3:
            printf("Location Function......");
            getch();
            main_menu(1);
            break;
        case 4:
            system("cls");
            printf("::::::::::Checkout Room::::::::::\n\n");
            printf("Enter Room No: ");scanf("%d", &item_id);
            order_room_update(0); //Update Room Status to Avalabile
            printf("\n\nRoom no: %d checkout successful. Press any key to continue.....", item_id);
            getch();
            main_menu(1);
            break;
        case 5:
            m=0;
            system("cls");
            printf("1. Search by ID\n");
            printf("2. Confirmed Order List\n");
            printf("3. Pending Order List\n");
            printf("4. Update Order\n");
            printf("5. Main Menu\n\n");
            printf("Enter choice: ");scanf("%d", &m);

            if(m==1) order_search(0);
            else if(m==2) order_search(1);
            else if(m==3) order_search(2);
            else if(m==4) update_order_status(1);

            getch();
            main_menu(1);
            break;
        case 6:
            room_menu(1);
            break;
        case 7:
            food_menu(1);
            break;
        case 8:
            employee_menu(1);
            getch();
            main_menu(1);
            break;
        case 9:
            printf("User Function.....");
            break;
        case 10:
            printf("Payment Function.....");
            break;
        case 11:
            contact();
            break;
        case 12:
            system("CLS");
            main();
            break;
        default:
            printf("Error: Invalid input...");
        }

    }
    else if(n==2) //user Menu
    {
        n=0;
        int m;
        printf(":::::::::User Menu::::::::::\n\n");
        printf("1. Book Room\n");
        printf("2. Order Food\n");
        printf("3. Order History\n");
        printf("4. User Profile\n");
        printf("5. Logout\n\n");
        printf("Enter choice: ");scanf("%d", &m);

        switch(m)
        {
            case 1:
                room_menu(2);
                break;
            case 2:
                food_menu(2);
                break;
            case 3:
                user_order_history();
                getch();
                main_menu(2);
                break;
            case 4:
                printf("User Profile Function");
                getch();
                main_menu(2);
                break;
            case 5:
                system("cls");
                main();
                break;
            default:
                printf("Error! Invalid input.");
        }
    }

}

/*
    ==================================================================================
                                    Room Function
    ==================================================================================
*/
void room_menu(int n)
{
    system("cls");
    int m;

    if(n==1) //Admin Room Menu
    {
        n=m=0;
        printf("::::::::::Admin Room Menu::::::::::\n\n");
        printf("1. Add Room\n");
        printf("2. Room List\n");
        printf("3. Update Room\n");
        printf("4. Delete Room\n");
        printf("5. Search Room\n");
        printf("6. Main Menu\n\n");
        printf("Enter choice: ");scanf("%d", &m);

        switch(m)
        {
        case 1:
            add_room();
            getch();
            room_menu(1);
            break;
        case 2:
            system("cls");
            room_list();
            getch();
            room_menu(1);
            break;
        case 3:
            update_room();
            getch();
            room_menu(1);
            break;
        case 4:
            delete_room();
            getch();
            room_menu(1);
            break;
        case 5:
            system("cls");
            m=0;
            printf("1. Search by Room no\n");
            printf("2. AC Room\n");
            printf("3. Non AC Room\n");
            printf("4. Available Room\n");
            printf("5. Not Available\n");
            printf("Enter choice: ");scanf("%d", &m);
            if(m==1) room_search(0);
            else if(m==2) room_search(1);
            else if(m==3) room_search(2);
            else if(m==4) room_search(3);
            else if(m==5) room_search(4);
            getch();
            room_menu(1);
            break;
        case 6:
            main_menu(1);
            break;
        default:
            printf("Error: invalid input");
        }
    }
    else if(n==2) //User Room Menu
    {
        n=m=0;
        printf("::::::::::User Room Menu::::::::::\n\n");
        printf("1. AC Room\n");
        printf("2. Non AC Room\n");
        printf("3. Main Menu\n\n");
        printf("Enter choice: ");scanf("%d", &m);

        switch (m)
        {
        case 1:
            room_search(1,2);
            break;
        case 2:
            room_search(2,2);
            break;
        case 3:
            main_menu(2);
            break;
        default:
            printf("Error: Invalid Input");
        }


    }

}

/*
    ==================================================================================
                                    Admin Add Room Function
    ==================================================================================
*/
void add_room()
{
    system("cls");
    FILE *fptr = fopen("room.txt", "ab+");

    struct room add;

    printf("::::::::::Add New Room::::::::::\n\n");
    printf("Enter Room No: ");scanf("%d", &add.no);
    printf("Enter Room Name: ");scanf("%s", &add.name);
    printf("Enter Room Features: ");scanf("%s", &add.features);
    printf("Enter Room Type (1. AC or 2. Non AC): ");scanf("%d", &add.type);
    printf("Enter Room Price: ");scanf("%d", &add.price);
    add.status = 0;

    fwrite(&add, sizeof(add), 1, fptr);
    fclose(fptr);

    printf("\n\n\nRoom No: %d\t|\tRoom Name: %s\t|\tRoom Features: %s\t|\tRoom Type: %d\t|\tRoom Price: %d tk\n\n", add.no, add.name, add.features, add.type, add.price);
    printf("Room Added Successful!\nPress any key to go Menu\n");

}

/*
    ==================================================================================
                                    Admin Room List Function
    ==================================================================================
*/
void room_list()
{
    FILE *fptr = fopen("room.txt", "rb");

    if(fptr == NULL)
    {
        printf("Error: Unable to open file.");
        exit(1);
    }
    struct room list;

    printf("::::::::::Room List::::::::::\n\n");
    while(fread(&list, sizeof(list), 1, fptr))
    {
        printf("Room No: %d", list.no);
        printf("\t|\tRoom Name: %s", list.name);
        printf("\t|\tRoom Features: %s", list.features);
        printf("\t|\tRoom Type: ");
        if(list.type == 1)
            printf("AC");
        else if(list.type == 2)
            printf("Non AC");
        printf("\t|\tRoom Price: %d", list.price);
        printf("\t|\tRoom Status: ");
        if(list.status == 0)
            printf("Available");
        else if(list.status == 1)
            printf("Not Available");
        printf("\n\n");
    }
    fclose(fptr);
}


/*
    ==================================================================================
                                    Admin Update Room Function
    ==================================================================================
*/
void update_room()
{
    system("cls");

    room_list();

    FILE *main_file;
    FILE *temp_file;

    char filename[100]="room.txt";
    int delete_line;
    struct room add;

    main_file  = fopen(filename, "rb+");
    temp_file = fopen("temp-file.tmp", "wb+");

    if (main_file == NULL || temp_file == NULL)
    {
        printf("Unable to open file.\n");
        exit(1);
    }

    printf("Replace Room No: ");
    scanf("%d", &delete_line);

    rewind(main_file);

    while(fread(&add, sizeof(add),1,main_file) == 1)
    {
        if(add.no != delete_line)
            fwrite(&add, sizeof(add), 1, temp_file);
        else if(add.no == delete_line)
        {
            printf("Updated Room No: ");scanf("%d", &add.no);
            printf("Updated Room Name: ");scanf("%s", &add.name);
            printf("Updated Room Features: ");scanf("%s", &add.features);
            printf("Updated Room Type (1. AC or 2. Non AC): ");scanf("%d", &add.type);
            printf("Updated Room Price: ");scanf("%d", &add.price);

            fwrite(&add, sizeof(add), 1, temp_file);
        }
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("\n\n");
    printf("::::::::::After Update::::::::::");
    room_list();
}


/*
    ==================================================================================
                                    Admin Delete Room Function
    ==================================================================================
*/
void delete_room()
{
    FILE *main_file;
    FILE *temp_file;

    char filename[100]="room.txt";
    int delete_line;
    struct room add, list;

    main_file  = fopen(filename, "rb+");
    temp_file = fopen("temp-file.tmp", "wb+");

    if (main_file == NULL || temp_file == NULL)
    {
        printf("Unable to open file.\n");
        exit(1);
    }

    room_list();

    printf("Delete Room No: ");
    scanf("%d", &delete_line);

    rewind(main_file);

    while(fread(&add, sizeof(add),1,main_file) == 1)
    {
        if(add.no != delete_line)
        {
            fwrite(&add, sizeof(add), 1, temp_file);
        }
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("::::::::::After Delete %d No Room::::::::::", delete_line);
    room_list();

    fclose(main_file);
}

/*
    ==================================================================================
                                    Admin Room Searching Function
    ==================================================================================
*/
void room_search(int n, int autho)
{
    system("cls");

    char filename[]="room.txt";

    FILE *fptr;
    fptr = fopen(filename, "rb");

    int num,flag=0;

    if (fptr == NULL)
    {
        printf("\n\nUnable to open file.\n");
        exit(1);
    }

    if(n==0)
    {
        printf("::::::::::Search Room by Room no::::::::::\n\n");
        printf("Enter Room no: ");
        scanf("%d", &num);
        printf("\n\n");
        while(fread(&room_info, sizeof(room_info),1,fptr) == 1)
        {
            if(room_info.no == num)
            {
                flag = 1;
                printf("Room No: %d", room_info.no);
                printf("\t|\tRoom Name: %s", room_info.name);
                printf("\t|\tRoom Features: %s", room_info.features);
                printf("\t|\tRoom Type: ");
                if(room_info.type == 1)
                    printf("AC");
                else if(room_info.type == 2)
                    printf("Non AC");
                printf("\t|\tRoom Price: %d", room_info.price);
                printf("\t|\tRoom Status: ");
                if(room_info.status == 0)
                    printf("Available");
                else if(room_info.status == 1)
                    printf("Not Available");
                printf("\n\n");
            }
        }
    }
    else if(n==1)
    {
        printf("::::::::::AC Room List::::::::::\n\n");
        while(fread(&room_info, sizeof(room_info),1,fptr) == 1)
        {
            if(room_info.type == 1)
            {
                flag = 1;
                printf("Room No: %d", room_info.no);
                printf("\t|\tRoom Name: %s", room_info.name);
                printf("\t|\tRoom Features: %s", room_info.features);
                printf("\t|\tRoom Type: ");
                if(room_info.type == 1)
                    printf("AC");
                else if(room_info.type == 2)
                    printf("Non AC");
                printf("\t|\tRoom Price: %d", room_info.price);
                printf("\t|\tRoom Status: ");
                if(room_info.status == 0)
                    printf("Available");
                else if(room_info.status == 1)
                    printf("Not Available");
                printf("\n\n");
            }
        }
    }
    else if(n==2)
    {
        printf("::::::::::Non AC Room List::::::::::\n\n");
        while(fread(&room_info, sizeof(room_info),1,fptr) == 1)
        {
            if(room_info.type == 2)
            {
                flag = 1;
                printf("Room No: %d", room_info.no);
                printf("\t|\tRoom Name: %s", room_info.name);
                printf("\t|\tRoom Features: %s", room_info.features);
                printf("\t|\tRoom Type: ");
                if(room_info.type == 1)
                    printf("AC");
                else if(room_info.type == 2)
                    printf("Non AC");
                printf("\t|\tRoom Price: %d", room_info.price);
                printf("\t|\tRoom Status: ");
                if(room_info.status == 0)
                    printf("Available");
                else if(room_info.status == 1)
                    printf("Not Available");
                printf("\n\n");
            }
        }
    }
    else if(n==3)
    {
        printf("::::::::::Available Room List::::::::::\n\n");
        while(fread(&room_info, sizeof(room_info),1,fptr) == 1)
        {
            if(room_info.status == 0)
            {
                flag = 1;
                printf("Room No: %d", room_info.no);
                printf("\t|\tRoom Name: %s", room_info.name);
                printf("\t|\tRoom Features: %s", room_info.features);
                printf("\t|\tRoom Type: ");
                if(room_info.type == 1)
                    printf("AC");
                else if(room_info.type == 2)
                    printf("Non AC");
                printf("\t|\tRoom Price: %d", room_info.price);
                printf("\t|\tRoom Status: ");
                if(room_info.status == 0)
                    printf("Available");
                else if(room_info.status == 1)
                    printf("Not Available");
                printf("\n\n");
            }
        }
    }
    else if(n==4)
    {
        printf("::::::::::Not Available Room List::::::::::\n\n");
        while(fread(&room_info, sizeof(room_info),1,fptr) == 1)
        {
            if(room_info.status == 1)
            {
                flag = 1;
                printf("Room No: %d", room_info.no);
                printf("\t|\tRoom Name: %s", room_info.name);
                printf("\t|\tRoom Features: %s", room_info.features);
                printf("\t|\tRoom Type: ");
                if(room_info.type == 1)
                    printf("AC");
                else if(room_info.type == 2)
                    printf("Non AC");
                printf("\t|\tRoom Price: %d", room_info.price);
                printf("\t|\tRoom Status: ");
                if(room_info.status == 0)
                    printf("Available");
                else if(room_info.status == 1)
                    printf("Not Available");
                printf("\n\n");
            }
        }
    }
    fclose(fptr);

    if(n==1 && autho==2 && flag==1)
    {
        int id;
        printf("Enter room ID which is you want to buy: ");scanf("%d", &id);
        order_room(id);
    }
    else if(n==2 && autho==2 && flag==1)
    {
        int id;
        printf("Enter room ID which is you want to buy: ");scanf("%d", &id);
        order_room(id);
    }
    else if(flag==0 && autho!=2)
    {
        printf("\nNot Found");
        getch();
        room_menu(1);
    }
    else if(flag==0 && autho==2)
    {
        printf("\nNot Found");
        getch();
        room_menu(2);
    }
}

/*
    ==================================================================================
                                    Food Function
    ==================================================================================
*/
void food_menu(int n)
{
    system("cls");
    int m=0;

    if(n==1) //Admin Food Menu
    {
        n=0;
        printf("::::::::::Admin Food Menu::::::::::\n\n");
        printf("1. Add Food\n");
        printf("2. Food List\n");
        printf("3. Update Food\n");
        printf("4. Delete Food\n");
        printf("5. Food Search\n");
        printf("6. Main Menu\n\n");
        printf("Enter Choice: ");scanf("%d", &m);

        switch(m)
        {
        case 1:
            add_food();
            getch();
            food_menu(1);
            break;
        case 2:
            food_list();
            getch();
            food_menu(1);
            break;
        case 3:
            update_food();
            getch();
            food_menu(1);
            break;
        case 4:
            delete_food();
            getch();
            food_menu(1);
            break;
        case 5:
            system("cls");
            m=0;
            printf("1. Search by Food ID\n");
            printf("2. Breakfast List\n");
            printf("3. Lunch List\n");
            printf("4. Snacks List\n");
            printf("5. Dinner List\n");
            printf("Enter choice: ");scanf("%d", &m);
            if(m==1)food_search(0);
            else if(m==2) food_search(1);
            else if(m==3) food_search(2);
            else if(m==4) food_search(3);
            else if(m==5) food_search(4);
            getch();
            food_menu(1);
            break;
        case 6:
            main_menu(1);
            break;
        default:
            printf("Error: invalid input");
        }
    }
    else if(n==2) //User Room Menu
    {
        n=m=0;
        printf("::::::::::User Food Menu::::::::::\n\n");

            printf("1. Breakfast List\n");
            printf("2. Lunch List\n");
            printf("3. Snacks List\n");
            printf("4. Dinner List\n");
            printf("5. Main Menu\n\n");
            printf("Enter choice: ");scanf("%d", &m);

            switch(m)
            {
            case 1:
                food_search(1, 2);
                break;
            case 2:
                food_search(2, 2);
                break;
            case 3:
                food_search(3, 2);
                break;
            case 4:
                food_search(4, 2);
                break;
            case 5:
                main_menu(2);
                break;
            default:
                printf("Error: Invalid input");
            }
    }
}

/*
    ==================================================================================
                                    Admin Add Food Function
    ==================================================================================
*/
void add_food()
{
    system("cls");
    FILE *fptr = fopen("food.txt", "ab+");

    printf("Enter Food Code: ");scanf("%d", &food_info.code);
    printf("Enter Food Name: ");scanf("%s", &food_info.name);
    printf("Enter Food Description: ");scanf("%s", &food_info.description);
    printf("Enter Food Category(1. Breakfast, 2. Lunch 3. Snacks, 4. Dinner): ");scanf("%d", &food_info.category);
    printf("Enter Food Price: ");scanf("%d", &food_info.price);
    food_info.status = 0;

    fwrite(&food_info, sizeof(food_info), 1, fptr);
    fclose(fptr);

    printf("\n\n\nFood Code %d\t|\tFood Name: %s\t|\tFood Description: %s\t|\tFood Category: %d\t|\tFood Price: %d tk\n\n", food_info.code, food_info.name, food_info.description, food_info.category, food_info.price);
    printf("Room Added Successful!\nPress any key to go Menu\n");

}

/*
    ==================================================================================
                                    Admin Food List Function
    ==================================================================================
*/
void food_list()
{
    FILE *fptr = fopen("food.txt", "rb");

    if(fptr == NULL)
    {
        printf("Error: Unable to open file.");
        exit(1);
    }

    printf("::::::::::Food List::::::::::\n\n");

    while(fread(&food_info, sizeof(food_info), 1, fptr) == 1)
    {
        printf("Food Code: %d", food_info.code);
        printf("\t|\t Food Name: %s", food_info.name);
        printf("\t|\t Food Description: %s", food_info.description);
        printf("\t|\t Food Category: ");
            if(food_info.category == 1) printf("Breakfast");
            else if(food_info.category == 2) printf("Lunch");
            else if(food_info.category == 3) printf("Snacks");
            else if(food_info.category == 4) printf("Dinner");
        printf("\t|\t Food Price: %d", food_info.price);
        printf("\t|\t Food Status: ");
            if(food_info.status == 0) printf("Available");
            else if(food_info.status == 1) printf("Not Available");
        printf("\n\n");
    }
    fclose(fptr);
}


/*
    ==================================================================================
                                    Admin Update Food Function
    ==================================================================================
*/
void update_food()
{
    system("cls");

    food_list();

    FILE *main_file;
    FILE *temp_file;

    char filename[100]="food.txt";
    int delete_line;

    main_file  = fopen(filename, "rb+");
    temp_file = fopen("temp-file.tmp", "wb+");

    if (main_file == NULL || temp_file == NULL)
    {
        printf("Unable to open file.\n");
        exit(1);
    }

    printf("Enter food code which is you want to update: ");
    scanf("%d", &delete_line);

    rewind(main_file);

    while(fread(&food_info, sizeof(food_info),1,main_file) == 1)
    {
        if(food_info.code != delete_line)
            fwrite(&food_info, sizeof(food_info), 1, temp_file);
        else if(food_info.code == delete_line)
        {
            printf("Updated Food Code: ");scanf("%d", &food_info.code);
            printf("Updated Food Name: ");scanf("%s", &food_info.name);
            printf("Updated Food Description: ");scanf("%s", &food_info.description);
            printf("Updated Food Category(1. Breakfast, 2. Lunch 3. Snacks, 4. Dinner): ");scanf("%d", &food_info.category);
            printf("Updated Food Price: ");scanf("%d", &food_info.price);

            fwrite(&food_info, sizeof(food_info), 1, temp_file);
        }
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("\n\n");
    printf("::::::::::After Update::::::::::");
    food_list();
}


/*
    ==================================================================================
                                    Admin Delete Food Function
    ==================================================================================
*/
void delete_food()
{
    FILE *main_file;
    FILE *temp_file;

    char filename[100]="food.txt";
    int delete_line;

    main_file  = fopen(filename, "rb+");
    temp_file = fopen("temp-file.tmp", "wb+");

    if (main_file == NULL || temp_file == NULL)
    {
        printf("Unable to open file.\n");
        exit(1);
    }

    food_list();

    printf("Enter food code which is you want to delete: ");
    scanf("%d", &delete_line);

    rewind(main_file);

    while(fread(&food_info, sizeof(food_info),1,main_file) == 1)
    {
        if(food_info.code != delete_line)
        {
            fwrite(&food_info, sizeof(food_info), 1, temp_file);
        }
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("::::::::::After Delete %d No Food::::::::::", delete_line);
    food_list();

    fclose(main_file);
}

/*
    ==================================================================================
                                    Admin Food Searching Function
    ==================================================================================
*/
void food_search(int n, int autho)
{
    system("cls");
    char filename[]="food.txt";

    FILE *fptr;
    fptr = fopen(filename, "rb");

    int num,flag=0;

    if (fptr == NULL)
    {
        printf("\n\nUnable to open file.\n");
        exit(1);
    }

    if(n==0)
    {
        printf("::::::::::Search Food by Food ID::::::::::\n\n");
        printf("Enter Food Code: ");
        scanf("%d", &num);
        printf("\n\n");

        while(fread(&food_info, sizeof(food_info),1,fptr) == 1)
        {
            if(food_info.code == num)
            {
                flag = 1;
                printf("Food Code: %d", food_info.code);
                printf("\t|\t Food Name: %s", food_info.name);
                printf("\t|\t Food Description: %s", food_info.description);
                printf("\t|\t Food Category: ");
                    if(food_info.category == 1) printf("Breakfast");
                    else if(food_info.category == 2) printf("Lunch");
                    else if(food_info.category == 3) printf("Snacks");
                    else if(food_info.category == 4) printf("Dinner");
                printf("\t|\t Food Price: %d", food_info.price);
                printf("\t|\t Food Status: ");
                    if(food_info.status == 0) printf("Available");
                    else if(food_info.status == 1) printf("Not Available");
                printf("\n\n");
            }
        }
    }
    else if(n==1)
    {
        printf("::::::::::Breakfast Food List::::::::::\n\n");
        while(fread(&food_info, sizeof(food_info),1,fptr) == 1)
        {
            if(food_info.category == 1)
            {
                flag = 1;
                printf("Food Code: %d", food_info.code);
                printf("\t|\t Food Name: %s", food_info.name);
                printf("\t|\t Food Description: %s", food_info.description);
                printf("\t|\t Food Category: ");
                    if(food_info.category == 1) printf("Breakfast");
                    else if(food_info.category == 2) printf("Lunch");
                    else if(food_info.category == 3) printf("Snacks");
                    else if(food_info.category == 4) printf("Dinner");
                printf("\t|\t Food Price: %d", food_info.price);
                printf("\t|\t Food Status: ");
                    if(food_info.status == 0) printf("Available");
                    else if(food_info.status == 1) printf("Not Available");
                printf("\n\n");
            }
        }
        if(autho==2 && flag==1)
        {
            int buy;
            printf("Enter food ID which is you want to buy: ");scanf("%d", &buy);
            order_food(buy);
        }
    }
    else if(n==2)
    {
        printf("::::::::::Lunch Food List::::::::::\n\n");
        while(fread(&food_info, sizeof(food_info),1,fptr) == 1)
        {
            if(food_info.category == 2)
            {
                flag = 1;
                printf("Food Code: %d", food_info.code);
                printf("\t|\t Food Name: %s", food_info.name);
                printf("\t|\t Food Description: %s", food_info.description);
                printf("\t|\t Food Category: ");
                    if(food_info.category == 1) printf("Breakfast");
                    else if(food_info.category == 2) printf("Lunch");
                    else if(food_info.category == 3) printf("Snacks");
                    else if(food_info.category == 4) printf("Dinner");
                printf("\t|\t Food Price: %d", food_info.price);
                printf("\t|\t Food Status: ");
                    if(food_info.status == 0) printf("Available");
                    else if(food_info.status == 1) printf("Not Available");
                printf("\n\n");
            }
        }
        if(autho==2 && flag==1)
        {
            int buy;
            printf("Enter food ID which is you want to buy: ");scanf("%d", &buy);
            order_food(buy);
        }
    }
    else if(n==3)
    {
        printf("::::::::::Snacks Food List::::::::::\n\n");
        while(fread(&food_info, sizeof(food_info),1,fptr) == 1)
        {
            if(food_info.category == 3)
            {
                flag = 1;
                printf("Food Code: %d", food_info.code);
                printf("\t|\t Food Name: %s", food_info.name);
                printf("\t|\t Food Description: %s", food_info.description);
                printf("\t|\t Food Category: ");
                    if(food_info.category == 1) printf("Breakfast");
                    else if(food_info.category == 2) printf("Lunch");
                    else if(food_info.category == 3) printf("Snacks");
                    else if(food_info.category == 4) printf("Dinner");
                printf("\t|\t Food Price: %d", food_info.price);
                printf("\t|\t Food Status: ");
                    if(food_info.status == 0) printf("Available");
                    else if(food_info.status == 1) printf("Not Available");
                printf("\n\n");
            }
        }
        if(autho==2 && flag==1)
        {
            int buy;
            printf("Enter food ID which is you want to buy: ");scanf("%d", &buy);
            order_food(buy);
        }
    }
    else if(n==4)
    {
        printf("::::::::::Dinner Food List::::::::::\n\n");
        while(fread(&food_info, sizeof(food_info),1,fptr) == 1)
        {
            if(food_info.category == 4)
            {
                flag = 1;
                printf("Food Code: %d", food_info.code);
                printf("\t|\t Food Name: %s", food_info.name);
                printf("\t|\t Food Description: %s", food_info.description);
                printf("\t|\t Food Category: ");
                    if(food_info.category == 1) printf("Breakfast");
                    else if(food_info.category == 2) printf("Lunch");
                    else if(food_info.category == 3) printf("Snacks");
                    else if(food_info.category == 4) printf("Dinner");
                printf("\t|\t Food Price: %d", food_info.price);
                printf("\t|\t Food Status: ");
                    if(food_info.status == 0) printf("Available");
                    else if(food_info.status == 1) printf("Not Available");
                printf("\n\n");
            }
        }
        if(autho==2 && flag==1)
        {
            int buy;
            printf("Enter food ID which is you want to buy: ");scanf("%d", &buy);
            order_food(buy);
        }
    }

    if(flag==0 && autho!=2)
    {
        printf("\nNot Found");
        getch();
        food_menu(1);
    }
    else if(flag==0 && autho==2)
    {
        printf("\nNot Found");
        getch();
        food_menu(2);
    }
    fclose(fptr);
}

/*
    ==================================================================================
                                    Employee Function
    ==================================================================================
*/
void employee_menu(int n)
{
    system("cls");
    int m=0;

    if(n==1) //Admin Employee Menu
    {
        n=0;
        printf("::::::::::Employee Menu::::::::::\n\n");
        printf("1. Add Employee\n");
        printf("2. Employee List\n");
        printf("3. Update Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Employee Search\n");
        printf("6. Main Menu\n\n");
        printf("Enter Choice: ");scanf("%d", &m);

        switch(m)
        {
        case 1:
            add_employee();
            getch();
            employee_menu(1);
            break;
        case 2:
            employee_list();
            getch();
            employee_menu(1);
            break;
        case 3:
            update_employee();
            getch();
            employee_menu(1);
            break;
        case 4:
            delete_employee();
            getch();
            employee_menu(1);
            break;
        case 5:
            employee_search();
            getch();
            employee_menu(1);
            break;
        case 6:
            main_menu(1);
            break;
        default:
            printf("Error: invalid input");
        }
    }
    else if(n==2) //User Room Menu
    {
        n=0;
        printf("::::::::::User Room Menu::::::::::\n\n");
    }
}

/*
    ==================================================================================
                                    Admin Add Employee Function
    ==================================================================================
*/
void add_employee()
{
    system("cls");
    FILE *fptr = fopen("employee.txt", "ab+");

    printf("Enter Employee ID: ");scanf("%d", &employee_info.id);
    printf("Enter Employee Name: ");scanf("%s", &employee_info.name);
    printf("Enter Employee Address: ");scanf("%s", &employee_info.address);
    printf("Enter Employee Salary: "); scanf("%ld", &employee_info.salary);

    fwrite(&employee_info, sizeof(employee_info), 1, fptr);
    fclose(fptr);

    printf("\n\n\nEmployee ID: %d\t|\tEmployee Name: %s\t|\tEmployee Address: %s\t|\tEmployee Salary: %ld\n\n", employee_info.id, employee_info.name, employee_info.address, employee_info.salary);
    printf("Employee Added Successful!\nPress any key to go Menu\n");
}

/*
    ==================================================================================
                                    Admin Employee List Function
    ==================================================================================
*/
void employee_list()
{
    FILE *fptr = fopen("employee.txt", "rb");

    if(fptr == NULL)
    {
        printf("Error: Unable to open file.");
        exit(1);
    }

    printf("::::::::::Employee List::::::::::\n\n");

    while(fread(&employee_info, sizeof(employee_info), 1, fptr) == 1)
    {
        printf("Employee ID: %d", employee_info.id);
        printf("\t|\t Employee Name: %s", employee_info.name);
        printf("\t|\t Employee Address: %s", employee_info.address);
        printf("\t|\t Employee Salary: %d", employee_info.salary);
        printf("\n\n");
    }
    fclose(fptr);
}


/*
    ==================================================================================
                                    Admin Update Employee Function
    ==================================================================================
*/
void update_employee()
{
    system("cls");

    employee_list();

    FILE *main_file;
    FILE *temp_file;

    char filename[100]="employee.txt";
    int delete_line;

    main_file  = fopen(filename, "rb+");
    temp_file = fopen("temp-file.tmp", "wb+");

    if (main_file == NULL || temp_file == NULL)
    {
        printf("Unable to open file.\n");
        exit(1);
    }

    printf("Enter employee ID which is you want to update: ");
    scanf("%d", &delete_line);

    rewind(main_file);

    while(fread(&employee_info, sizeof(employee_info),1,main_file) == 1)
    {
        if(employee_info.id != delete_line)
            fwrite(&employee_info, sizeof(employee_info), 1, temp_file);
        else if(employee_info.id == delete_line)
        {
            printf("Updated Employee ID: ");scanf("%d", &employee_info.id);
            printf("Updated Employee Name: ");scanf("%s", &employee_info.name);
            printf("Updated Employee Address: ");scanf("%s", &employee_info.address);
            printf("Updated Employee Salary: "); scanf("%ld", &employee_info.salary);

            fwrite(&employee_info, sizeof(employee_info), 1, temp_file);
        }
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("\n\n");
    printf("::::::::::After Update::::::::::");
    employee_list();
}


/*
    ==================================================================================
                                    Admin Delete Employee Function
    ==================================================================================
*/
void delete_employee()
{
    system("cls");

    FILE *main_file;
    FILE *temp_file;

    char filename[100]="employee.txt";
    int delete_line;

    main_file  = fopen(filename, "rb+");
    temp_file = fopen("temp-file.tmp", "wb+");

    if (main_file == NULL || temp_file == NULL)
    {
        printf("Unable to open file.\n");
        exit(1);
    }

    employee_list();

    printf("Enter employee ID which is you want to delete: ");
    scanf("%d", &delete_line);

    rewind(main_file);

    while(fread(&employee_info, sizeof(employee_info),1,main_file) == 1)
    {
        if(employee_info.id != delete_line)
        {
            fwrite(&employee_info, sizeof(employee_info), 1, temp_file);
        }
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("::::::::::After Delete %d No Employee ID::::::::::", delete_line);
    employee_list();
}

/*
    ==================================================================================
                                    Admin Employee Searching Function
    ==================================================================================
*/
void employee_search()
{
    system("cls");

    employee_list();printf("\n\n");

    char filename[]="employee.txt";

    FILE *fptr;
    fptr = fopen(filename, "rb");

    int num,flag=0;

    if (fptr == NULL)
    {
        printf("\n\nUnable to open file.\n");
        exit(1);
    }

    printf("Enter employee ID: ");
    scanf("%d", &num);

    printf("\n\n");

    while(fread(&employee_info, sizeof(employee_info),1,fptr) == 1)
    {
        if(employee_info.id == num)
        {
            flag = 1;
            printf("Employee ID: %d", employee_info.id);
            printf("\t|\t Employee Name: %s", employee_info.name);
            printf("\t|\t Employee Address: %s", employee_info.address);
            printf("\t|\t Employee Salary: %d", employee_info.salary);
            printf("\n\n");
        }
    }
    if(flag==0)
        printf("\nNot Found");

    fclose(fptr);
}

/*
    ==================================================================================
                                    Admin Order Searching Function
    ==================================================================================
*/
void order_search(int n)
{
    system("cls");
    char filename[]="order.txt";

    FILE *fptr;
    fptr = fopen(filename, "rb");

    int num,flag=0;

    if (fptr == NULL)
    {
        printf("\n\nUnable to open file.\n");
        exit(1);
    }

    if(n==0)
    {
        printf("::::::::::Search Food by Order ID::::::::::\n\n");
        printf("Enter Order ID: ");
        scanf("%d", &num);
        printf("\n\n");

        while(fread(&order_info, sizeof(order_info),1,fptr) == 1)
        {
            if(order_info.or_id == num)
            {
                flag = 1;
                printf("Order ID: %d\t|\t", order_info.or_id);
                printf("Item ID: %d\t|\t", order_info.item_id);
                printf("Item Name: %s\t|\t", order_info.or_name);
                printf("Item Type: %s\t|\t", order_info.or_type);
                printf("Quantity: %d\t|\t", order_info.item_count);
                printf("Total price: %ld\t|\t", order_info.or_price);
                printf("User: %s\t|\t", order_info.or_user);
                printf("Status: ");
                    if(order_info.or_status==0) printf("Pending");
                    else if(order_info.or_status == 1) printf("Confirmed");
                printf("\n\n");
            }
        }
    }
    else if(n==1)
    {
        printf("::::::::::Confirmed Order List::::::::::\n\n");
        while(fread(&order_info, sizeof(order_info),1,fptr) == 1)
        {
            if(order_info.or_status == 1)
            {
                flag = 1;
                printf("Order ID: %d\t|\t", order_info.or_id);
                printf("Item ID: %d\t|\t", order_info.item_id);
                printf("Item Name: %s\t|\t", order_info.or_name);
                printf("Item Type: %s\t|\t", order_info.or_type);
                printf("Quantity: %d\t|\t", order_info.item_count);
                printf("Total price: %ld\t|\t", order_info.or_price);
                printf("User: %s\t|\t", order_info.or_user);
                printf("Status: ");
                    if(order_info.or_status==0) printf("Pending");
                    else if(order_info.or_status == 1) printf("Confirmed");
                printf("\n\n");
            }
        }
    }
    else if(n==2)
    {
        printf("::::::::::Pending Order List::::::::::\n\n");
        while(fread(&order_info, sizeof(order_info),1,fptr) == 1)
        {
            if(order_info.or_status == 0)
            {
                flag = 1;
                printf("Order ID: %d\t|\t", order_info.or_id);
                printf("Item ID: %d\t|\t", order_info.item_id);
                printf("Item Name: %s\t|\t", order_info.or_name);
                printf("Item Type: %s\t|\t", order_info.or_type);
                printf("Quantity: %d\t|\t", order_info.item_count);
                printf("Total price: %ld\t|\t", order_info.or_price);
                printf("User: %s\t|\t", order_info.or_user);
                printf("Status: ");
                    if(order_info.or_status==0) printf("Pending");
                    else if(order_info.or_status == 1) printf("Confirmed");
                printf("\n\n");
            }
        }
    }

    fclose(fptr);

    if(flag==0)
        printf("\nNot Order Found");

    getch();
    main_menu(1);
}

/*
    ==================================================================================
                                    User Order History Function
    ==================================================================================
*/
void user_order_history()
{
    system("cls");
    char filename[]="order.txt";

    FILE *fptr;
    fptr = fopen(filename, "rb");

    int num,flag=0;

    if (fptr == NULL)
    {
        printf("\n\nUnable to open file.\n");
        exit(1);
    }

    printf("::::::::::Order History::::::::::\n\n");
    while(fread(&order_info, sizeof(order_info),1,fptr) == 1)
    {
        if(strcmp(order_info.or_user,username)==0)
        {
            flag = 1;
            printf("Order ID: %d\t|\t", order_info.or_id);
            printf("Item ID: %d\t|\t", order_info.item_id);
            printf("Item Name: %s\t|\t", order_info.or_name);
            printf("Item Type: %s\t|\t", order_info.or_type);
            printf("Quantity: %d\t|\t", order_info.item_count);
            printf("Total price: %ld\t|\t", order_info.or_price);
            printf("User: %s\t|\t", order_info.or_user);
            printf("Status: ");
                if(order_info.or_status==0) printf("Pending");
                else if(order_info.or_status == 1) printf("Confirmed");
            printf("\n\n");
        }
    }
    fclose(fptr);

    if(flag==0)
        printf("\nNot Order Found");

    getch();
    main_menu(2);
}

/*
    ==================================================================================
                                    Order Room Function
    ==================================================================================
*/
void order_room(int id)
{
    system("cls");

    FILE *main_file;
    FILE *temp_or_file;

    char filename[100]="room.txt";
    int flag=0;

    main_file  = fopen(filename, "rb");
    temp_or_file = fopen("temp-order-file.tmp", "wb+");

    if (main_file == NULL || temp_or_file == NULL)
    {
        printf("Unable to open file.\n");
        exit(1);
    }

    while(fread(&room_info, sizeof(room_info),1,main_file) == 1 && flag==0)
    {
        if(room_info.no == id && room_info.status==0)
        {
            flag=1;

            printf("Check ID Date(D-M-Y): ");scanf("%s", &order_info.in_date);
            printf("Check Out Date (D-M-Y): ");scanf("%s", &order_info.out_date);
            printf("How Many Rooms: ");scanf("%d", &order_info.item_count);
            printf("How Many Adults: ");scanf("%d", &order_info.adult_count);
            printf("How Many Children: ");scanf("%d", &order_info.children_count);

            strcpy(order_info.or_user, username);
            order_info.item_id=room_info.no;
            strcpy(order_info.or_name, room_info.name);
            if(room_info.type==1) strcpy(order_info.or_type, "AC");
            else if(room_info.type==2) strcpy(order_info.or_type, "Non AC");
            order_info.or_price = room_info.price*order_info.item_count;

            fwrite(&order_info, sizeof(order_info), 1, temp_or_file);
        }
    }
    fclose(main_file);
    fclose(temp_or_file);

    if(flag==1)
    {
        payment(1);
    }
    else
    {
        remove("temp-order-file.tmp");
        printf("%d Room not Available\n\n", id);
        getch();
        room_menu(2);
    }
}

/*
    ==================================================================================
                                    Order Food Function
    ==================================================================================
*/
void order_food(int id)
{
    system("cls");

    FILE *main_file;
    FILE *temp_or_file;

    char filename[100]="food.txt";
    int flag=0;

    main_file  = fopen(filename, "rb");
    temp_or_file = fopen("temp-order-file.tmp", "wb+");

    if (main_file == NULL || temp_or_file == NULL)
    {
        printf("Unable to open file.\n");
        exit(1);
    }

    while(fread(&food_info, sizeof(food_info),1,main_file) == 1 && flag==0)
    {
        if(food_info.code == id && food_info.status==0)
        {
            flag=1;

            printf("Food Quantity: ");scanf("%d", &order_info.item_count);

            strcpy(order_info.or_user, username);
            order_info.item_id=food_info.code;
            strcpy(order_info.or_name, food_info.name);
            if(food_info.category == 1) strcpy(order_info.or_type,"Breakfast");
            else if(food_info.category == 2) strcpy(order_info.or_type, "Lunch");
            else if(food_info.category == 3) strcpy(order_info.or_type, "Snacks");
            else if(food_info.category == 4) strcpy(order_info.or_type, "Dinner");
            order_info.or_price = food_info.price*order_info.item_count;

            fwrite(&order_info, sizeof(order_info), 1, temp_or_file);
        }
    }
    fclose(main_file);
    fclose(temp_or_file);

    if(flag==1)
    {
        payment(2);
    }
    else
    {
        remove("temp-order-file.tmp");
        printf("%d Food not Available\n\n", id);
        getch();
        food_menu(2);
    }
}

/*
    ==================================================================================
                                    Order Details Function
    ==================================================================================
*/
void order_details(int n)
{
    FILE *fptr;
    fptr = fopen("temp-order-file.tmp", "rb");

    printf("::::::::::Order Details::::::::::\n\n");

    if (fptr == NULL)
    {
        printf("\n\nUnable to open file.\n");
        exit(1);
    }

    if(n==1) //Room Order Details
    {
        while(fread(&order_info, sizeof(order_info),1,fptr)==1)
        {
            item_id = order_info.item_id;
            printf("Room No: %d\n", order_info.item_id);
            printf("Room Name: %s\n", order_info.or_name);
            printf("Room Type: %s\n", order_info.or_type);
            printf("Check in date: %s\n", order_info.in_date);
            printf("Check out date: %s\n", order_info.out_date);
            printf("Rooms: %d\n", order_info.item_count);
            printf("Adult: %d\n", order_info.adult_count);
            printf("Children: %d\n", order_info.children_count);
            printf("Total price: %ld\n", order_info.or_price);
            //printf("Username: %s", order_info.or_user);

            printf("\n\n");
        }
    }
    else if(n==2) //Food Order Details
    {
        while(fread(&order_info, sizeof(order_info),1,fptr)==1)
        {
            item_id = order_info.item_id;
            printf("Food Code: %d\n", order_info.item_id);
            printf("Food Name: %s\n", order_info.or_name);
            printf("Food Type: %s\n", order_info.or_type);
            printf("Food Quantity: %d\n", order_info.item_count);
            printf("Total price: %ld\n", order_info.or_price);
            //printf("Username: %s", order_info.or_user);

            printf("\n\n");
        }
    }

    fclose(fptr);

}

/*
    ==================================================================================
                                    Payment Function
    ==================================================================================
*/
void payment(int n)
{
    system("CLS");

    if(n==1) order_details(1); //Room Order Details
    else if(n==2) order_details(2); //Food Order Details

    printf("::::::::::Payment options::::::::::\n\n");
    int m;
    printf("1. Visa/Credit/MasterCard\n");
    printf("2. Bkash/Rocket\n");
    printf("3. Cash\n\n");
    printf("Enter choice: ");scanf("%d", &m);

    switch(m)
    {
    case 1:
        card(n);
        break;
    case 2:
        m_banking(n);
        break;
    case 3:
        thanks(n, 0);
        printf("Pay in Cash\n");
        break;
    default:
        printf("Error! Invalid Input..");
        getch();
        main_menu(2);
    }
}

/*
    ==================================================================================
                                    Card Payment Function
    ==================================================================================
*/
void card(int n)
{
    system("CLS");
    if(n==1) order_details(1); //Room Order Details
    else if(n==2) order_details(2); //Food Order Details

    char c;

    printf("::::::::::Payment > Card Information::::::::::\n\n");
    printf("Enter Card No\t\t: ");scanf("%d", &payment_info.no);

    printf("Enter Card Expire Date\t: ");scanf("%s", &payment_info.expire);
    printf("Enter CVC No\t\t: ");scanf("%d", &payment_info.code);

    printf("Confirm Payment (Y/N): ");scanf("%s", &c);

    system("CLS");

    if(c=='Y')
    {
        thanks(n, 1);
    }
    else
    {
        printf("Payment Deny..............");
        main_menu(2);
    }
}

/*
    ==================================================================================
                                    Mobile Banking Payment Function
    ==================================================================================
*/
void m_banking(int n)
{
    system("cls");
    if(n==1) order_details(1); //Room Order Details
    else if(n==2) order_details(2); //Food Order Details

    char c;

    printf("::::::::::Payment > Mobile Banking Information::::::::::\n\n");
    printf("Enter Your Mobile Banking (Bkash/Rocket) Number: ");scanf("%d", &payment_info.no);
    printf("Enter Your PIN: ");scanf("%d", &payment_info.code);
    printf("Confirm Payment (Y/N): ");scanf("%s", &c);

    system("CLS");

    if(c=='Y')
    {
        thanks(n, 1);
    }
    else
        printf("Payment Deny..............\n");
}

/*
    ==================================================================================
                                    Checkout Function
    ==================================================================================
*/
void thanks(int n, int m)
{
    system("cls");

    printf("                ##########  ##     ##      ##      ###    ##  ##   ##   #####                    \n");
    printf("                    ##      ##     ##     ####     ## #   ##  ## ##    #                         \n");
    printf("                    ##      #########    ##  ##    ##  #  ##  ###       #####                    \n");
    printf("                    ##      ##     ##   ## ## ##   ##   # ##  ## ##          #                   \n");
    printf("                    ##      ##     ##  ##      ##  ##    ###  ##   ##   #####                    \n\n");
    printf("##############################################################################################   \n\n");

    if(n==1) order_details(1); //Room Order Details
    else if(n==2) order_details(2); //Food Order Details

    if(n==1 && m==1) //Room Auto Payment
    {
        update_order(1);
        order_room_update(1);
    }
    else if(n==1 && m==0) //Room, Cash Payment
        update_order(0);
    else if(n==2 && m==1) //Food Payment
        update_order(1);
    else if(n==2 && m==0) //Food, Cash Payment
        update_order(0);

    getch();
    main_menu(2);
}

/*
    ==================================================================================
                                    Update Order List Function
    ==================================================================================
*/
void update_order(int n)
{
    FILE *main_file;
    FILE *temp_file;
    char filename[100]="order.txt";

    main_file  = fopen(filename, "ab+");
    temp_file = fopen("temp-order-file.tmp", "rb");

    int count=1;

    if (main_file == NULL || temp_file == NULL)
    {
        printf("Unable to open file.\n");
        exit(1);
    }

    while(fread(&order_info, sizeof(order_info),1,main_file) == 1)
    {
        count++;
    }

    while(fread(&order_info, sizeof(order_info),1,temp_file) == 1)
    {
        order_info.or_id = count;
        if(n==1)
            order_info.or_status = 1;
        else
            order_info.or_status = 0;

        fwrite(&order_info, sizeof(order_info), 1, main_file);
    }

    fclose(main_file);
    fclose(temp_file);

    remove("temp-order-file.tmp");
}

/*
    ==================================================================================
                                    Update Room Status Function
    ==================================================================================
*/
void order_room_update(int n)
{
    FILE *fptr, *fptr_temp1;

    fptr = fopen("room.txt", "rb");
    fptr_temp1 = fopen("temp-file.tmp", "wb+");

    if (fptr==NULL || fptr_temp1==NULL)
    {
        printf("Error: Unable to open file\n\n");
        exit(1);
    }

    rewind(fptr);

    while(fread(&room_info, sizeof(room_info), 1, fptr) == 1)
    {
        if(room_info.no != item_id)
            fwrite(&room_info, sizeof(room_info), 1, fptr_temp1);
        else if(room_info.no == item_id)
        {
            if(n==0) room_info.status = 0; //Checkout: Change Room Status to Avalabile
            else if(n==1) room_info.status = 1; //Order: Change Room Status to Not Avalabile

            fwrite(&room_info, sizeof(room_info), 1, fptr_temp1);
        }
    }

    fclose(fptr);
    fclose(fptr_temp1);

    remove("room.txt");
    rename("temp-file.tmp", "room.txt");
}

/*
    ==================================================================================
                                    Update Order Status Function
    ==================================================================================
*/
void update_order_status(int n)
{
    FILE *main_file;
    FILE *temp_file;
    char filename[100]="order.txt";

    main_file  = fopen(filename, "rb");
    temp_file = fopen("temp-file.tmp", "wb+");

    int count;

    if (main_file == NULL || temp_file == NULL)
    {
        printf("Unable to open file.\n");
        exit(1);
    }

    printf("Enter order ID: ");scanf("%d", &count);

    rewind(main_file);

    while(fread(&order_info, sizeof(order_info),1,main_file) == 1)
    {
        if(order_info.or_id != count)
            fwrite(&order_info, sizeof(order_info), 1, temp_file);
        else if(order_info.or_id == count)
        {
            if(n==0) order_info.or_status = 0; //Change Order Status to Pending
            if(n==1) order_info.or_status = 1; //Change order status to Confirmed

            fwrite(&order_info, sizeof(order_info), 1, temp_file);
        }
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("\n\n%d No Order Confirmed. Press any key to continue.....", count);
}

