#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

struct admin
{
    char name[100];
    char username[50];
    char password[100];
    char email[50];
    char nationality[20];
};
struct user
{
    char name[100];
    char username[50];
    char email[50];
    char password[100];
    char nid[50];
    char address[100];
    char nationality[20];
};
struct employee
{
    char name[100];
    char address[100];
    long salary;
};
struct room
{
    int no;
    char name[50];
    char features[200];
    int type;
    int price;
};
struct food
{
    char code[25];
    char name[50];
    char description[200];
    int price;
};
struct order
{
    char in_date[25];
    char out_date[25];
    int item_count;
    int adult_count;
    int children_count;
    int price;
};
struct payment
{
    int no;
    int code;
    char expire;
};
int contact()
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

//Display File all Content
int print_file(FILE *fptr)
{
    char ch;

    while((ch = fgetc(fptr)) != EOF)
        putchar(ch);
}

//Delete or Remove File Row
int delete_file_row(FILE *main_file, FILE *temp_file, const int delete_line)
{
    char buffer[255];
    int count = 1;

    while ((fgets(buffer, 255, main_file)) != NULL)
    {
        if (delete_line != count)
            fputs(buffer, temp_file);

        count++;
    }
}

//Update or Replace File Row
int replace_row(char filename[], int delete_line)
{
    FILE *main_file;
    FILE *temp_file;
    FILE *repl_file;

    int count=1;
    char buffer[255];
    char replace[255];

    main_file = fopen(filename, "r");
    repl_file = fopen("rep-file.tmp", "r");
    temp_file = fopen("temp-file.tmp", "w");

    if (main_file == NULL || temp_file == NULL || repl_file == NULL)
    {
        printf("\n\nUnable to open file.\n");
        exit(1);
    }

    fgets(replace, 250, repl_file);

    rewind(main_file);

    while ((fgets(buffer, 250, main_file)) != NULL)
    {
        if (delete_line != count)
            fputs(buffer, temp_file);
        else
            fputs(replace, temp_file);

        count++;
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    remove("rep-file.tmp");

    rename("temp-file.tmp", filename);

    printf("\n\n\t\t\tUpdated List (%d no Row).\n\n", delete_line);
    main_file = fopen(filename, "r");
    print_file(main_file);

    fclose(main_file);
}

//Food list
int food_list()
{
    FILE *fp = fopen("food.txt", "r");
    char buff_food[255];

    if(fp == NULL)
    {
       printf("Unable to open file!");
       exit(1);
    }

    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::        Food List       ::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    while(fgets(buff_food, sizeof(buff_food), fp) != NULL)
        {
            fputs(buff_food, stdout);
            fputs("\n\n", stdout);
        }
    fclose(fp);
}

//Room list
int room_list()
{
    FILE *fp = fopen("room.txt", "r");
    char buff_room[255];

    if(fp == NULL)
    {
       printf("Unable to open file!");
       exit(1);
    }
    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::        Room List       ::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    while(fgets(buff_room, sizeof(buff_room), fp) != NULL)
        {
            fputs(buff_room, stdout);
            fputs("\n\n", stdout);
        }
    fclose(fp);
}

//Delete Food Row
int delete_food()
{
    FILE *main_file;
    FILE *temp_file;

    char filename[100]="food.txt";
    int delete_line;

    main_file  = fopen(filename, "r");
    temp_file = fopen("temp-file.tmp", "w");

    if (main_file == NULL || temp_file == NULL)
    {
        printf("Unable to open file.\n");
        exit(1);
    }

    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::       Delete Food      ::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    print_file(main_file);

    printf("Delete Food Row: ");
    scanf("%d", &delete_line);

    rewind(main_file);

    delete_file_row(main_file, temp_file, delete_line);

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("\nFood Lists after removing %d Row.\n\n", delete_line);
    main_file = fopen(filename, "r");
    print_file(main_file);

    fclose(main_file);
}

//Delete Room Row
int delete_room()
{
    FILE *main_file;
    FILE *temp_file;

    char filename[100]="room.txt";
    int delete_line;

    main_file  = fopen(filename, "r");
    temp_file = fopen("temp-file.tmp", "w");

    if (main_file == NULL || temp_file == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read/write previleges.\n");

        exit(EXIT_FAILURE);
    }

    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::       Delete Room      ::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    print_file(main_file);

    printf("Delete Room Row: ");
    scanf("%d", &delete_line);

    rewind(main_file);

    delete_file_row(main_file, temp_file, delete_line);

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("\n\nRoom Lists after removing %d Row.\n\n", delete_line);
    main_file = fopen(filename, "r");
    print_file(main_file);

    fclose(main_file);
}

//Update Room List
int update_food()
{
    char filename[]="food.txt";

    FILE *fptr;
    FILE *rep_file;

    fptr = fopen(filename, "r");
    rep_file = fopen("rep-file.tmp", "w");

    struct food update;
    int delete_line;

    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::       Update Food      ::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    print_file(fptr);

    printf("\n\nUpdate Food Row: ");
    scanf("%d", &delete_line);

    printf("Enter Food Code: ");scanf("%s", &update.code);
    printf("Enter Food Name: ");scanf("%s", &update.name);
    printf("Enter Food Description: ");scanf("%s", &update.description);
    printf("Enter Food Price: ");scanf("%d", &update.price);

    fprintf(rep_file,"Food Code: %s\t|\tFood Name: %s\t|\tFood Discreption: %s\t|\tFood Price: %d tk\n", update.code, update.name, update.description, update.price);
    fclose(fptr);
    fclose(rep_file);

    replace_row(filename, delete_line);

}

//Update Room List
int update_room()
{
    char filename[]="room.txt";

    FILE *fptr;
    FILE *rep_file;

    fptr = fopen(filename, "r");
    rep_file = fopen("rep-file.tmp", "w");

    struct room update;
    int delete_line;

    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::       Update Room      ::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    print_file(fptr);

    printf("\n\nUpdate Room Row: ");
    scanf("%d", &delete_line);

    printf("Enter Room No: ");scanf("%d", &update.no);
    printf("Enter Room Name: ");scanf("%s", &update.name);
    printf("Enter Room Features: ");scanf("%s", &update.features);
    printf("Enter Room Type (1. AC or 2. Non AC): ");scanf("%d", &update.type);
    printf("Enter Room Price: ");scanf("%d", &update.price);

    fprintf(rep_file,"Room No: %d\t|\tRoom Name: %s\t|\tRoom Features: %s\t|\tRoom Type: %d\t|\tRoom Price: %d tk\n", update.no, update.name, update.features, update.type, update.price);
    fclose(fptr);
    fclose(rep_file);

    replace_row(filename, delete_line);

}

//Update Employee List
int update_employee()
{
    char filename[]="employee.txt";

    FILE *fptr;
    FILE *rep_file;

    fptr = fopen(filename, "r");
    rep_file = fopen("rep-file.tmp", "w");

    struct employee update;
    int delete_line;

    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::    Update Employee     ::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    print_file(fptr);

    printf("\n\nUpdate Employee Row: ");
    scanf("%d", &delete_line);

    printf("Enter Employee Name: ");scanf("%s", &update.name);
    printf("Enter Employee Address: ");scanf("%s", &update.address);
    printf("Enter Employee Salary: "); scanf("%ld", &update.salary);

    fprintf(rep_file,"Employee Name: %s\t|\tEmployee Address: %s\t|\tEmployee Salary: %ld\n", update.name, update.address, update.salary);
    fclose(fptr);
    fclose(rep_file);

    replace_row(filename, delete_line);

}

//Admin Food Add Function
int add_food()
{
    FILE *fptr;
    fptr = fopen("food.txt", "a");

    struct food add;

    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::      Add New Food      ::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    printf("Enter Food Code: ");scanf("%s", &add.code);
    printf("Enter Food Name: ");scanf("%s", &add.name);
    printf("Enter Food Description: ");scanf("%s", &add.description);
    printf("Enter Food Price: ");scanf("%d", &add.price);

    fprintf(fptr,"Food Code: %s\t|\tFood Name: %s\t|\tFood Discreption: %s\t|\tFood Price: %d tk\n", add.code, add.name, add.description, add.price);
    fclose(fptr);

    printf("Food Added Successful!\nPress any key to go Menu\n");
}

//Admin Room Add Function
int add_room()
{
    FILE *fptr;
    fptr = fopen("room.txt", "a");

    struct room add;

    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::      Add New Room      ::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    printf("Enter Room No: ");scanf("%d", &add.no);
    printf("Enter Room Name: ");scanf("%s", &add.name);
    printf("Enter Room Features: ");scanf("%s", &add.features);
    printf("Enter Room Type (1. AC or 2. Non AC): ");scanf("%d", &add.type);
    printf("Enter Room Price: ");scanf("%d", &add.price);

    fprintf(fptr,"Room No: %d\t|\tRoom Name: %s\t|\tRoom Features: %s\t|\tRoom Type: %d\t|\tRoom Price: %d tk\n", add.no, add.name, add.features, add.type, add.price);
    fclose(fptr);

    printf("\n\n\nRoom No: %d\t|\tRoom Name: %s\t|\tRoom Features: %s\t|\tRoom Type: %d\t|\tRoom Price: %d tk\n\n", add.no, add.name, add.features, add.type, add.price);
    printf("Room Added Successful!\nPress any key to go Menu\n");

}

//Admin Employee Add Function
int add_employee()
{

    FILE *fptr;
    fptr = fopen("employee.txt", "a");

    struct employee add;

    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::    Add New Employee    ::::::::::\n");
    printf("\t\t\t::                                        ::\n");
    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    printf("Enter Employee Name: ");scanf("%s", &add.name);
    printf("Enter Employee Address: ");scanf("%s", &add.address);
    printf("Enter Employee Salary: "); scanf("%ld", &add.salary);

    fprintf(fptr,"Employee Name: %s\t|\tEmployee Address: %s\t|\tEmployee Salary: %ld\n", add.name, add.address, add.salary);
    fclose(fptr);

    printf("\n\n\nEmployee Name: %s\t|\tEmployee Address: %s\t|\tEmployee Salary: %ld\n\n", add.name, add.address, add.salary);
    printf("Employee Added Successful!\nPress any key to go Menu\n");
}

//Admin Food Menu
int admin_food_menu()
{
    system("CLS");
    int N;

    printf("1. Add Food\n2. Food List\n3. Update Food\n4. Delete Food\n5. Main Menu\n\n");
    printf("Enter Choice: ");scanf("%d", &N);

    switch(N)
    {
    case 1:
        system("CLS");
        add_food();
        getch();
        admin_food_menu();
        break;
    case 2:
        system("CLS");
        food_list();
        getch();
        admin_food_menu();
        break;
    case 3:
        system("CLS");
        update_food();
        getch();
        admin_food_menu();
        break;
    case 4:
        system("CLS");
        delete_food();
        getch();
        admin_food_menu();
        break;
    case 5:
        main_menu(1);
        break;
    default:
        printf("Error: Invalid Input...");
    }
}

//Admin Room Menu
int admin_room_menu()
{
    system("CLS");
    int N;

    printf("1. Add Room\n2. Room List\n3. Update Room\n4. Delete Room\n5. Main Menu\n\n");
    printf("Enter Choice: ");scanf("%d", &N);

    switch(N)
    {
    case 1:
        system("CLS");
        add_room();
        getch();
        admin_room_menu();
        break;
    case 2:
        system("CLS");
        room_list();
        getch();
        admin_room_menu();
        break;
    case 3:
        system("CLS");
        update_room();
        getch();
        admin_room_menu();
        break;
    case 4:
        system("CLS");
        delete_room();
        getch();
        admin_room_menu();
        break;
    case 5:
        main_menu(1);
        break;
    default:
        printf("Error: Invalid Input...");
    }
}
//Admin Employee Menu
int admin_employee_menu()
{
    system("CLS");
    int N;

    printf("1. Add Employee\n2. Employee List\n3. Update Employee\n4. Delete Employee\n5. Main Menu\n\n");
    printf("Enter Choice: ");scanf("%d", &N);

    switch(N)
    {
    case 1:
        system("CLS");
        add_employee();
        getch();
        admin_employee_menu();
        break;
    case 2:
        system("CLS");
        room_list();
        getch();
        admin_employee_menu();
        break;
    case 3:
        system("CLS");
        update_employee();
        getch();
        admin_employee_menu();
        break;
    case 4:
        system("CLS");
        delete_room();
        getch();
        admin_employee_menu();
        break;
    case 5:
        main_menu(1);
        break;
    default:
        printf("Error: Invalid Input...");
    }
}
int hotel_features()
{
    FILE *fptr;
    fptr = fopen("hotel.txt", "w");

    char a[25];
    printf("Enter Hotel Features: ");scanf("%s", &a);

    fprintf(fptr,"%s, ", a);
    fclose(fptr);

    printf("Hotel Features Added Successful!\nPress any key to go Main Menu\n");
    getch();
    main_menu(1);

}


//End Order
int thanks()
{
    printf("                ##########  ##     ##      ##      ###    ##  ##   ##   #####                    \n");
    printf("                    ##      ##     ##     ####     ## #   ##  ## ##    #                         \n");
    printf("                    ##      #########    ##  ##    ##  #  ##  ###       #####                    \n");
    printf("                    ##      ##     ##   ## ## ##   ##   # ##  ## ##          #                   \n");
    printf("                    ##      ##     ##  ##      ##  ##    ###  ##   ##   #####                    \n\n");
    printf("##############################################################################################   \n\n");
    printf("Payment is Confirmed..........\n");
    printf("\n\t\tOrder Details\n\n");

    FILE *fp;
    char buff[255];//creating char array to store data of file
    fp = fopen("temp_order.txt", "r");

    print_file(fp);

    fclose(fp);
    remove("temp_order.txt");

    getch();
    main_menu(2);
}

//Card Payment Function
int card(int price)
{
    system("CLS");
    struct payment card;
    printf("Enter Card No\t\t: ");scanf("%d", &card.no);
    printf("Enter Card Expire Date\t: ");scanf("%s", &card.expire);
    printf("Enter CVC No\t\t: ");scanf("%d", &card.code);
    printf("Total Price is\t\t: %d\n", price);

    char c;
    printf("Confirm Payment (Y/N): ");scanf("%s", &c);

    system("CLS");

    if(c=='Y')
    {
        thanks();
    }
    else
        printf("Payment Deny..............");
}

//Mobile Banking Payment Function
int m_banking(int price)
{
    system("CLS");

    struct payment m_bank;

    printf("Enter Your Mobile Banking (Bkash/Rocket) Number: ");scanf("%d", &m_bank.no);
    printf("Enter Your PIN: ");scanf("%d", &m_bank.code);

    char c;
    printf("Confirm Payment (Y/N): ");scanf("%s", &c);

    system("CLS");

    if(c=='Y')
    {
        printf("Payment Confirm..........\n");
        thanks();
    }
    else
        printf("Payment Deny..............\n");
}

//Payment Function
int payment(int price)
{
    system("CLS");
    int N;
    printf("1. Visa/Credit/MasterCard\n2. Bkash/Rocket\n3. Cash\n");
    printf("Enter Choice: ");scanf("%d", &N);

    switch(N)
    {
    case 1:
        card(price);
        break;
    case 2:
        m_banking(price);
        break;
    case 3:
        thanks();
        printf("Pay in Cash\n");
        break;
    default:
        printf("Error! Invalid Input..");
        getch();
        main_menu(2);
    }
}

//Order Function
int order(int a)
{
    system("CLS");
    if(a==1)
    {
        struct order room;
        printf("Check ID Date(D-M-Y): ");scanf("%s", &room.in_date);
        printf("Check Out Date (D-M-Y): ");scanf("%s", &room.out_date);
        printf("How Many Rooms: ");scanf("%d", &room.item_count);
        printf("How Many Adults: ");scanf("%d", &room.adult_count);
        printf("How Many Children: ");scanf("%d", &room.children_count);

        system("CLS");
        printf("Please Re-Check Your Order And Confirm..\n");
        printf("Check IN Date\t: %s\n", room.in_date);
        printf("Check Out Date\t: %s\n", room.out_date);
        printf("Rooms\t\t: %d\n", room.item_count);
        printf("Adults\t\t: %d\n", room.adult_count);
        printf("Children\t: %d\n", room.children_count);

        FILE *fptr;
        fptr = fopen("temp_order.txt", "w");
        fprintf(fptr, "Check ID Date(D-M-Y)\t: %s\nCheck Out Date\t: %s\nRooms\t\t: %d\nAdults\t\t: %d\nChildren\t: %d\n", room.in_date, room.out_date, room.item_count, room.adult_count, room.children_count);
        fclose(fptr);

        char c;
        printf("To Confirm Your Order (Y/N): ");scanf("%s", &c);
        if(c=='Y')
        {
            payment(25640);
        }
        else
            printf("Order Deny..............");
        getch();
        room_menu();

    }
    else if(a==2)
    {
        printf("Food Order Function\n");
        payment(1200);
    }
    getch();
    main_menu(2);
}

//User Dinner Food List Fuunction
int dinner_food_list()
{
    system("CLS");
    printf("Dinner Food List");
    getch();
    order(2);
}

//User Snacks Food List Function
int snacks_food_list()
{
    system("CLS");
    printf("                     ######  ###    ##     ##       #####   ##   ##   ######    \n");
    printf("                    #        ## #   ##    ####     ##    #  ## ##    #          \n");
    printf("                     #####   ##  #  ##   ##  ##    ##       ###       #####     \n");
    printf("                          #  ##   # ##  ## ## ##   ##    #  ## ##          #    \n");
    printf("                    ######   ##    ### ##      ##   #####   ##   ##  ######     \n\n");
    printf("###############################################################################################\n\n");
    printf("\t\t##      Name        ##      Price       ##\n" );
    printf("\t\t------------------------------------------\n" );
    printf("\t\t1.      Berger          --  250 tk      ##\n" );
    printf("\t\t2.      Sandwich        --  180 tk      ##\n" );
    printf("\t\t3.      Beef Stick      --  350 tk      ##\n" );
    printf("\t\t4.      Nachos          --  200 tk      ##\n" );
    printf("\t\t5.      Sicilian Pizza  --  550 tk      ##\n" );
    printf("\t\t6.      Mango Juces     --  80  tk      ##\n" );
    printf("\t\t7.      Chicken Fry     --  450 tk      ##\n" );
    printf("\t\t8.      Water 1 Lt.     --  50  tk      ##\n" );
    printf("\t\t9.      Water 2 Lt.     --  95  tk      ##\n" );

    getch();
    order(2);
}

//User Lunch Food List Function
int lunch_food_list()
{
    system("CLS");
    printf("                    ##       ##   ##  ###    ##   #####   ##    ##  \n");
    printf("                    ##       ##   ##  ## #   ##  ##    #  ##    ##  \n");
    printf("                    ##       ##   ##  ##  #  ##  ##       ########  \n");
    printf("                    ##    #  ##   ##  ##   # ##  ##    #  ##    ##  \n");
    printf("                    ######    #####   ##    ###   #####   ##    ##  \n\n");
    printf("######################################################################################\n\n");
    printf("\t\t##      Name        ##      Price       ##\n" );
    printf("\t\t------------------------------------------\n" );
    printf("\t\t1.      Rice        --      60  tk      ##\n" );
    printf("\t\t2.      Fried Rice  --      250 tk      ##\n" );
    printf("\t\t3.      Beef        --      360 tk      ##\n" );
    printf("\t\t4.      Mutton      --      450 tk      ##\n" );
    printf("\t\t5.      Pulses      --      40  tk      ##\n" );
    printf("\t\t6.      Kabab       --      160 tk      ##\n" );
    printf("\t\t7.      Fish        --      250 tk      ##\n" );
    printf("\t\t8.      Vegetable   --      50  tk      ##\n" );
    printf("\t\t9.      Chicken     --      280 tk      ##\n" );
    getch();
    order(2);
}

//User Breakfast Food List Function
int breakfast_food_list()
{
    system("CLS");
    printf("            #####   #####   #####      ##       #####   ##   ##  #####     ##      #####   ######## \n");
    printf("            ##  ##  ##  ##  ##        ####     ##    #  ## ##    ##       ####    #           ##    \n");
    printf("            #####   #####   #####    ##  ##    ##       ###      #####   ##  ##    #####      ##    \n");
    printf("            ##  ##  ## ##   ##      ## ## ##   ##    #  ## ##    ##     ## ## ##        #     ##    \n");
    printf("            #####   ##  ##  #####  ##      ##   #####   ##   ##  ##    ##      ##  #####      ##    \n\n");
    printf("###############################################################################################################\n\n");
    printf("\t\t##      Name        ##      Price       ##\n" );
    printf("\t\t------------------------------------------\n" );
    printf("\t\t1.      Bread       --      100 tk      ##\n" );
    printf("\t\t2.      Eggs        --      60  tk      ##\n" );
    printf("\t\t3.      Coffee      --      200 tk      ##\n" );
    printf("\t\t4.      Green Tea   --      150 tk      ##\n" );
    printf("\t\t5.      Normal Tea  --      80  tk      ##\n" );
    printf("\t\t6.      Nuts        --      500 tk      ##\n" );
    printf("\t\t7.      Nun Bread   --      70  tk      ##\n" );
    printf("\t\t8.      Vegetable   --      50  tk      ##\n" );

    getch();
    order(2);
}

//User Food Main Menu Function
int food_menu()
{
    system("CLS");
    int fm;
    printf("1. Breakfast\n2. Lunch\n3. Snacks\n4. Dinner\n5. Food Menu\n6. Main Menu\n");
    printf("Enter Choice: "); scanf("%d", &fm);
    switch (fm)
    {
    case 1:
        breakfast_food_list();
        break;
    case 2:
        lunch_food_list();
        break;
    case 3:
        snacks_food_list();
        break;
    case 4:
        dinner_food_list();
        break;
    case 5:
        food_menu();
        break;
    case 6:
        main_menu(2);
        break;
    default:
        printf("Invalid Input! [Food Menu]");

    }
}

//User AC Room List Function
int ac_room_list()
{
    printf("                       ##       #####      ######    ######    ######   ###     ###  \n");
    printf("                      ####     ##    #     ##    #  ##    ##  ##    ##  ## #   # ##   \n");
    printf("                     ##  ##    ##          ######   ##    ##  ##    ##  ##  # #  ##   \n");
    printf("                    ## ## ##   ##    #     ##   #   ##    ##  ##    ##  ##   #   ##   \n");
    printf("                   ##      ##   #####      ##    #   ######    ######   ##       ##   \n\n");
    printf("######################################################################################################\n\n");
    printf("\t\t##      Name            ##  Price       ##\n" );
    printf("\t\t------------------------------------------\n" );
    printf("\t\t1.      Room Name 1     --  2000 tk     ##\n" );
    printf("\t\t2.      Room Name 2     --  2200 tk     ##\n" );
    printf("\t\t3.      Room Name 3     --  2500 tk     ##\n" );
    printf("\t\t4.      Room Name 4     --  1950 tk     ##\n" );
    printf("\t\t5.      Room Name 5     --  2890 tk     ##\n" );
    printf("\t\t6.      Room Name 6     --  3500 tk     ##\n" );

    getch();
    order(1);
}

//User Non AC Room List Function
int non_ac_room_list()
{
    printf("        ###    ##   ######   ###    ##        ##       #####      ######    ######    ######   ###     ###          \n");
    printf("        ## #   ##  ##    ##  ## #   ##       ####     ##    #     ##    #  ##    ##  ##    ##  ## #   # ##          \n");
    printf("        ##  #  ##  ##    ##  ##  #  ##      ##  ##    ##          ######   ##    ##  ##    ##  ##  # #  ##          \n");
    printf("        ##   # ##  ##    ##  ##   # ##     ## ## ##   ##    #     ##   #   ##    ##  ##    ##  ##   #   ##          \n");
    printf("        ##    ###   ######   ##    ###    ##      ##   #####      ##    #   ######    ######   ##       ##          \n\n");
    printf("##################################################################################################################  \n\n");
    printf("\t\t##      Name            ##  Price       ##\n" );
    printf("\t\t------------------------------------------\n" );
    printf("\t\t1.      Room Name 1     --  2000 tk     ##\n" );
    printf("\t\t2.      Room Name 2     --  2200 tk     ##\n" );
    printf("\t\t3.      Room Name 3     --  2500 tk     ##\n" );
    printf("\t\t4.      Room Name 4     --  1950 tk     ##\n" );
    printf("\t\t5.      Room Name 5     --  2890 tk     ##\n" );
    printf("\t\t6.      Room Name 6     --  3500 tk     ##\n" );

    getch();
    order(1);
}

//User Room Main Menu Function
int room_menu()
{
    system("CLS");
    int rm;
    printf("1. AC Room\n2. Non AC Room\n3. Main Menu\n\n");
    printf("Enter choice: "); scanf("%d", &rm);
    switch(rm)
    {
    case 1:
        system("CLS");
        ac_room_list();
        break;
    case 2:
        system("CLS");
        non_ac_room_list();
        break;
    case 3:
        main_menu(2);
        break;
    default:
        printf("Error: Invalid Input");
    }
}

//User Login Function
int user_login()
{
    system("CLS");
    char username[50], password[100];


    FILE *log;
    log = fopen("user_info.txt", "r");
    struct user login;
    printf("Username: ");scanf("%s", &username);
    printf("Password: ");scanf("%s", &password);


    while(fread(&login, sizeof(login), 1, log))
    {
        if(strcmp(username,login.username)==0 && strcmp(password,login.password)==0)
            printf("User Login Succesful\n");
        else
        {
            printf("Incorrect Username or Password. Please Try again\nPress any key to try again...");
            getch();
            system("CLS");
            user_login();
        }
    }

    fclose(log);

    main_menu(2);
}

//Admin Login Function
int admin_login()
{
    system("CLS");
    char username[50], password[100];


    FILE *log;
    log = fopen("admin_info.txt", "r");
    struct admin login;
    printf("Username: ");scanf("%s", &username);
    printf("Password: ");scanf("%s", &password);


    while(fread(&login, sizeof(login), 1, log))
    {
        if(strcmp(username,login.username)==0 && strcmp(password,login.password)==0)
            printf("User Login Succesful\n");
        else
        {
            printf("Incorrect Username or Password. Please Try again\nPress any key to try again...");
            getch();
            system("CLS");
            admin_login();
        }
    }

    fclose(log);

    main_menu(1);
}

//Admin and User Registetion function
int registation(int N)
{
    if (N == 1)
    {
        FILE *reg;
        reg = fopen("admin_info.txt", "w");
        struct admin add;

        printf("Enter username: ");scanf("%s", add.username);
        printf("Enter your name: ");scanf("%s", add.name);
        printf("Enter your email: ");scanf("%s", add.email);
        printf("Enter a password: ");scanf("%s", add.password);
        printf("Enter your nationality: ");scanf("%s", add.nationality);

        fwrite(&add, sizeof(add), 1, reg);
        fclose(reg);

        printf("\n\nRegistation Sussefull\n\nPress any key to Login...");
        getch();
        system("CLS");
        admin_login();
    }
    else if (N == 2)
    {
        FILE *reg;
        reg = fopen("user_info.txt", "w");
        struct user add;

        printf("Enter username: ");scanf("%s", add.username);
        printf("Enter your name: ");scanf("%s", add.name);
        printf("Enter your email: ");scanf("%s", add.email);
        printf("Enter a password: ");scanf("%s", add.password);
        printf("Enter your NID/Passport no: ");scanf("%s", add.nid);
        printf("Enter your address: ");scanf("%s", add.address);
        printf("Enter your nationality: ");scanf("%s", add.nationality);

        fwrite(&add, sizeof(add), 1, reg);
        fclose(reg);

        printf("\tRegistation Sussefull\nPress any key to Login...");
        getch();
        system("CLS");
        user_login();
    }
}

//Admin and User Main Menu
int main_menu(int i)
{
    system("CLS");
    if(i==1)
    {
        int N;
        printf("        ## Admin Menu ##\n\n");
        printf("1. Hotel Name\n2. Hotel Features\n3. Location\n4. Transport\n5. Order\n6. Room\n7. Food\n8. Employee\n9. User\n10. Payment\n11. Contact\n12. Logout\n\n");
        printf("Enter Choice: ");scanf("%d", &N);

        switch(N)
        {
        case 1:
            printf("Hotel Name Function");
            getch();
            main_menu(1);
            break;
        case 2:
            system("CLS");
            hotel_features();
            break;
        case 3:
            printf("Location Function......");
            getch();
            main_menu(1);
            break;
        case 4:
            printf("Transport Function.....");
            getch();
            main_menu(1);
            break;
        case 5:
            printf("Order Function....");
            getch();
            main_menu(1);
            break;
        case 6:
            admin_room_menu();
            break;
        case 7:
            admin_food_menu();
            break;
        case 8:
            admin_employee_menu();
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
    else if(i==2)
    {
        int a;
        printf("\t\t### User Menu ###\n");
        printf("1. Book Room\n2. Order Food\n3. Order History\n4. User Profile\n5. Logout\n");
        printf("Enter choice: ");
        scanf("%d", &a);

        switch(a)
        {
            case 1:
                room_menu();
                break;
            case 2:
                food_menu();
                break;
            case 3:
                printf("Order History Function");
                getch();
                main_menu(2);
                break;
            case 4:
                printf("User Profile Function");
                getch();
                main_menu(2);
                break;
            case 5:
                system("CLS");
                main();
                break;
            default:
                printf("Error! Invalid input.");
        }
    }
}

//Main Function
int main()
{
    int n;
    /*
    printf("\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t::                                         ::\n");
    printf("\t\t\t::                                         ::\n");
    printf("\t\t\t:::::::::: Hotel Management System ::::::::::\n");
    printf("\t\t\t::                                         ::\n");
    printf("\t\t\t::                                         ::\n");
    printf("\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    printf("\t\t\t\t1. User System\n\t\t\t\t2. Admin System\n\n");
    printf("\t\t\t\tEnter your choice: "); scanf("%d", &n);*/

    int x; double y;
    char text1[]=    "\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n\t\t\t::                                         ::\n\t\t\t::                                         ::\n\t\t\t:::::::::: Hotel Management System ::::::::::\n\t\t\t::                                         ::\n\t\t\t::                                         ::\n\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n\n\n";
    char text2[]=    "\t\t\t\t1. User System\n\t\t\t\t2. Admin System\n\n";
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

    system("CLS");
    if(n==1)
    {
        n=0;
        printf("1. Login\n2. Registation\n");
        printf("Enter choice: "); scanf("%d", &n);
        system("CLS");
        if(n==1)
            user_login();
        else if(n==2)
            registation(2);
        else
            printf("Invalid Input!");
    }
    else if(n==2)
    {
        n=0;
        printf("1. Login\n2. Registation\n");
        printf("Enter choice: "); scanf("%d", &n);
        system("CLS");
        if(n==1)
            admin_login();
        else if(n==2)
            registation(1);
        else
            printf("Invalid Input!\n");
    }

    else
        printf("Invalid Input!\n");

    return 0;
}
