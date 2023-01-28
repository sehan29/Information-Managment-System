#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>

void front_desk();
void report_header();
int report_body();
void report_bottom();
int course_registation();
void course_reg(char name[]);
void new_course_adding();
int new_student();
int setting_gpv();
void update_curicular_data();
void testting();
void c_testting();
void c_testting2();
void update_course_details();
void update_gpv();
void delete_st_details();
void all_details();

struct couse_del{

    char couse_id[10];
    char date[20];
    float gpv_value;

};

struct c_students{

    char st_name[40];
    char st_index[40];
    char st_department[20];
    struct couse_del courses_id[20];
    int number_of_courses;

};

struct u_course{


    char new_course_id[40];
    char new_course_name[40];
    char new_creadit_value[40];
    struct c_students dj;
    

};

struct u_course f_student;
struct u_course c_registation;
struct u_course f_student2;


FILE *student_details;
FILE *course_details;
FILE *temp_file;
FILE *student_details11;

int main()
{

int select_aspect = 0;
    do
    {
    
    front_desk();
    printf("Enter Related Number :: ");
    scanf("%d",&select_aspect);
    
    switch (select_aspect)
    {
    case 1:
    {
        system("cls");
        new_student();
        break;
    }     
    case 2:
    {
        system("cls");
        new_course_adding();
        break;
    }
    case 3:
    {
        system("cls");
        course_registation();
        break;
    }
    case 4:
    {
        system("cls");
        setting_gpv();
        break;
    }
    case 5:
    {
        system("cls");
        report_header();
        break;
    }
    case 6:
    {
        system("cls");
        update_curicular_data();
        break;
    }
    case 7:
    {
        system("cls");
        update_course_details();
        break;
    }
    case 8:
    {
        system("cls");
        update_gpv();
        break;
    }
    case 9:
    {
        delete_st_details();
        break;
    }
    case 11:
    {
        system("cls");
        printf("\t\t---- BYE ----");
        exit(0); 

        break;

    }
    case 14:
    {
        system("cls");
        c_testting();
        break;
    }
    case 12:
    {
        system("cls");
        c_testting2();
        break;
    }
    case 13:
    {

        system("cls");
        testting();
        
        break;
    }
    case 10:
    {
        all_details();
        break;
    }
    default:
    printf("---- Invalid Character ----");
        break;
    }
    

    } while (select_aspect !=  11);




    return 0;
}

void front_desk()
{

    printf("\n1.Add a New Student.");
    printf("\n2.Add a New Course For List.");
    printf("\n3.To Register a New Course.");
    printf("\n4.Insert GPV Values Of Student.");
    printf("\n5.Generate a Report.");
    printf("\n6.Update Student General Data.");
    printf("\n7.Update Registered Course.");
    printf("\n8.Update GPA.");
    printf("\n9.Delete The Student Details.");
    printf("\n10.Display all Details of students.");
    printf("\n11.Exit.\n\n");

}

void report_header()
{
    char st_index[10];
    char *temp_course;
    FILE *st_detail;
    FILE *c_details;
    float gpa_value = 0;
    int condition_temp_value = 0;
    int number_of_courses = 0;
    st_detail = fopen("student_detail.txt","r");
    
    struct u_course course_del;
    struct u_course reading_details;
    printf("Enter Index Number : ");
    scanf("%s",&st_index);
    while(fread(&reading_details,sizeof(struct u_course),1,st_detail))
    {
        condition_temp_value = strcmp(st_index,reading_details.dj.st_index);
        if(!(condition_temp_value))
        {
            printf("\n\n\t\t--- GPA Calculatting System ---");
            printf("\n\nStudent Name : %s",reading_details.dj.st_name);
            printf("\nIndex Number : %s",reading_details.dj.st_index);
            printf("\nDepartment : %s",reading_details.dj.st_department);
            printf("\nDate : %s",__DATE__);
            printf("\n--------------------------------------------------------");
            printf("\nCourse Id");
            printf("\tCourse Name");
            printf("\t\tGPV");
            printf("\tGrade\n\n"); 
            for(int i = 0; i <= reading_details.dj.number_of_courses; i++)
            {
              c_details = fopen("scourse_detail.txt","r");
                 printf("%s",reading_details.dj.courses_id[i].couse_id);
              //  printf("\t\t%s",temp_course);
                while(fread(&course_del,sizeof(struct u_course),1,c_details))
                {
                    int p1 = strcmp(reading_details.dj.courses_id[i].couse_id,course_del.new_course_id);
                    if(!(p1))
                    {
                         printf("\t\t%s",course_del.new_course_name);
                        
                    }
                 
                } 
                fclose(c_details);
                printf("\t\t%.2f",reading_details.dj.courses_id[i].gpv_value);
                if(reading_details.dj.courses_id[i].gpv_value >= 4.000000)
                {
                    printf("\t%s\n","A");
                }
                else if(3.900001 >= reading_details.dj.courses_id[i].gpv_value && 3.000000 <= reading_details.dj.courses_id[i].gpv_value)
                {
                    printf("\t%s\n","B");
                 //   printf("%f",reading_details.dj.courses_id[i].gpv_value);
                }
                else if (2.91 > reading_details.dj.courses_id[i].gpv_value & 2.500000 <= reading_details.dj.courses_id[i].gpv_value )
                {
                    printf("\t%s\n","C");
                     
                }
                else if(2.400000 >= reading_details.dj.courses_id[i].gpv_value && 1.500000 <= reading_details.dj.courses_id[i].gpv_value)
                {
                    printf("\t%s\n","D");
                }
                else{
                    printf("\t%s\n","E");
                }
                number_of_courses = reading_details.dj.number_of_courses;

                gpa_value = gpa_value + reading_details.dj.courses_id[i].gpv_value;
                
            }

        }

        
    }
  //  printf("%f",gpa_value);
  number_of_courses = number_of_courses + 1;
  // printf("%d",number_of_courses);
   float k = gpa_value/(float)number_of_courses;
   printf("\n\nGPA value : %.3f",k);
/*     printf("\n\n\t\t--- MY REPORT OF THE UNIVERCITY ---");
    printf("\n\nStudent Name : ");
    printf("\nIndex Number : ");
    printf("\nDepartment : ");
    printf("\nDate : ");
    printf("\n---------------------------------------------------------------------");
    printf("\nCourse Id");
    printf("\t\tCourse Name");
    printf("\t\tGPV");
    printf("\t\tGrade");  */ 
    fclose(st_detail);
    printf("\n\n");
    report_bottom();

}

int report_body()
{
     
    printf("------------------------------------------------------------------");
    report_bottom();
    return 0;
}

void report_bottom()
{
        printf("-------------------------------------------------------\n");


    printf(" A = 4.0      B = 3.0        C = 2.5        D = 1.5       E = 0\n\n");
}

int course_registation()
{
    char condition[10];
    int i = 0,h , s;
    int found = 0;
    int s1;
    struct u_course tmp_del;
    struct u_course ttmp;
    temp_file = fopen("my_temp_file.txt","w");
    FILE *student_details11 = fopen("student_detail.txt","r");
    fflush(stdin);
    char my_index[20];
    char m[10];
    char temp_condition[10];
    printf("Enter Your Index Number : ");
    fgets(my_index,20,stdin);
    my_index[strlen(my_index)-1]='\0';
    course_reg(my_index);
    printf("\nIf you want to add a new course (Y/N)");
    scanf("%s",&m);
    int k = strcmp(m,"Y");
    if(!(k))
    {
         c_testting();

        while(fread(&tmp_del,sizeof(struct u_course),1,student_details11))
        {
            int p = strcmp(my_index,tmp_del.dj.st_index);
            if(!(p))
            {
                found = 1;

                h = tmp_del.dj.number_of_courses;
               
               /*  fgets(f_student.dj.courses_id[h+1],20,stdin);
                my_index[strlen(my_index)-1]='\0'; */

              //  f_student.dj.st_index = tmp_del.dj.st_index;
                strcpy(tmp_del.dj.st_index,tmp_del.dj.st_index);
                strcpy(tmp_del.dj.st_name,tmp_del.dj.st_name);
                strcpy(tmp_del.dj.st_department,tmp_del.dj.st_department);
                for(i = 0; i <= h; i++)
                {
                    strcpy(tmp_del.dj.courses_id[i].couse_id,tmp_del.dj.courses_id[i].couse_id);
                    strcpy(tmp_del.dj.courses_id[i].date,tmp_del.dj.courses_id[i].date);
                    tmp_del.dj.courses_id[i].gpv_value = tmp_del.dj.courses_id[i].gpv_value;
                }

              
                
              h = h+1;
                 
                    printf("\nEnter Course code :");
                    scanf("%s",&tmp_del.dj.courses_id[h].couse_id);
                    strcpy(tmp_del.dj.courses_id[h].couse_id,tmp_del.dj.courses_id[h].couse_id);
                   // printf("%s",tmp_del.dj.courses_id[h].couse_id);
                    strcpy(tmp_del.dj.courses_id[h].date,__DATE__);
                    
                
                tmp_del.dj.number_of_courses = h;
                
                
            }

            fwrite(&tmp_del,sizeof(struct u_course),1,temp_file);

           
        }

           printf("\n\t\t ----- Submited ----- ");
      //  student_details = fopen("student_detail.txt","r");
       // printf("Enter Course Code : ");
      //  fgets(c_registation.new_course_id,20,stdin);

    }
    else{

        printf("exit");
    }
    fclose(temp_file);
    fclose(student_details11);

    if(found)
    {

        temp_file = fopen("my_temp_file.txt","r");
        student_details11 = fopen("student_detail.txt","w");
        while(fread(&ttmp,sizeof(struct u_course),1,temp_file))
        {
            fwrite(&ttmp,sizeof(struct u_course),1,student_details11);
        }

    }
    fclose(temp_file);
    fclose(student_details11);
    
    return 0;

}

void course_reg(char name[])
{
    struct u_course readding_del;
    struct u_course readding_course;
    student_details = fopen("student_detail.txt","r");
    

    while(fread(&readding_del,sizeof(struct u_course),1,student_details))
    {
         int k = strcmp(readding_del.dj.st_index,name);
         if(!(k))
         {
            printf("\n\n\t\t------ My Course ------ ");
            printf("\n\nStudent Name : %s",readding_del.dj.st_name);
            printf("\nIndex Number : %s",readding_del.dj.st_index);
            printf("\nDepartment : %s",readding_del.dj.st_department);
            printf("\n----------------------------------------------");
            printf("\nCourse Id");
            printf("\t\tCourse Name\n");
            for(int i = 0; i <= readding_del.dj.number_of_courses; i++)
            {
                printf("\n- %s",readding_del.dj.courses_id[i].couse_id);
                course_details = fopen("scourse_detail.txt","r");
                while(fread(&readding_course,sizeof(struct u_course),1,course_details))
                {
                    int temp_con = strcmp(readding_del.dj.courses_id[i].couse_id,readding_course.new_course_id);
                    if(!(temp_con))
                    {
                        printf("                %s",readding_course.new_course_name);
                    }
                }
                fclose(course_details);
            }

            
            
         }

    }
    printf("\n----------------------------------------------");
   
  /*   printf("\n\n\t\t------ My Course ------ ");
    printf("\n\nStudent Name : ");
    printf("\nIndex Number : ");
    printf("\nDepartment : ");
    printf("\n---------------------------------------------------------------------");
    printf("\nCourse Id");
    printf("\t\tCourse Name\n"); */
    fclose(student_details);
   // fclose(course_details);


}

int setting_gpv()
{
    struct u_course readding_temp;
    struct u_course redding_2;
    char temp_name[20];
    int k;
    int found = 0;
    FILE *student_details111;
    FILE *student_details12 = fopen("student_detail.txt","r");
    temp_file = fopen("all_temp_details.txt","w");
    fflush(stdin);
    printf("Enter Index Number : ");
    fgets(temp_name,20,stdin);
    temp_name[strlen(temp_name)-1]='\0';

/*     while(fread(&readding_temp,sizeof(struct u_course),1,student_details12))
        {
          //  printf("1243");
            fwrite(&readding_temp,sizeof(struct u_course),1,temp_file);
        }
        fclose(temp_file);
        fclose(student_details12);
        temp_file = fopen("all_temp_details.txt","r");
        FILE *student_details111 = fopen("student_detail.txt","w");
     //   printf("1243555");
        while(fread(&readding_temp,sizeof(struct u_course),1,temp_file))
        {
          //  printf("888888");
            int j = strcmp(temp_name,readding_temp.dj.st_index);
            if(!(j))
            {
             //   printf("99999");
                strcpy(f_student.dj.st_name,readding_temp.dj.st_name);
                strcpy(f_student.dj.st_index,readding_temp.dj.st_index);
                strcpy(f_student.dj.st_department,readding_temp.dj.st_department);
             //   printf("999991114");
                f_student.dj.number_of_courses = readding_temp.dj.number_of_courses;
             //   printf("9222222222");
                printf("\n\n %d number of courses \n",f_student.dj.number_of_courses);

                for(int i = 0; i <= readding_temp.dj.number_of_courses; i++)
                {
                  //  printf("999991114");
                    strcpy(f_student.dj.courses_id[i].couse_id,readding_temp.dj.courses_id[i].couse_id);
                    strcpy(f_student.dj.courses_id[i].date,readding_temp.dj.courses_id[i].date);
                    f_student.dj.courses_id[i].gpv_value = readding_temp.dj.courses_id[i].gpv_value;
                    printf("\n%f\n",readding_temp.dj.courses_id[i].gpv_value);
                    if(f_student.dj.courses_id[i].gpv_value == 0.000000)
                    {

                    printf("\nCourse code : %s",readding_temp.dj.courses_id[i].couse_id);
                    printf("\nEnter The GPV value : ");
                    scanf("%f",&readding_temp.dj.courses_id[i].gpv_value);
                    f_student.dj.courses_id[i].gpv_value = readding_temp.dj.courses_id[i].gpv_value;
                    printf("\nMy GPV value is %f ",readding_temp.dj.courses_id[i].gpv_value);

                    }
                  
                }
                
            }
            fwrite(&f_student,sizeof(struct u_course),1,student_details111);

        }
        fclose(temp_file);
        fclose(student_details111); */

   /*      student_details111 = fopen("student_detail.txt","r");
        while(fread(&redding_2,sizeof(struct u_course),1,student_details111))
        {
            int s = strcmp(temp_name,redding_2.dj.st_index);
            if(!(s))
            {

            printf("\nIndex id : %s ",redding_2.dj.st_index);

            for(int i = 0; i <= readding_temp.dj.number_of_courses; i++)
            {
                printf("\ncorse code : %s",redding_2.dj.courses_id[i].couse_id);
                printf("\n mygpv value %f",redding_2.dj.courses_id[i].gpv_value);
            }

            }

            

        }
        fclose(student_details111); */
 


 while(fread(&readding_temp,sizeof(struct u_course),1,student_details12))
 {
    k = strcmp(temp_name,readding_temp.dj.st_index);
    if(!(k))
    {
        found = 1;
        strcpy(f_student.dj.st_index,readding_temp.dj.st_index);
        strcpy(f_student.dj.st_name,readding_temp.dj.st_name);
        strcpy(f_student.dj.st_department,readding_temp.dj.st_department);
        f_student.dj.number_of_courses = readding_temp.dj.number_of_courses;

        for(int i = 0; i <= f_student.dj.number_of_courses; i++)
        {
            strcpy(f_student.dj.courses_id[i].couse_id,readding_temp.dj.courses_id[i].couse_id);
            strcpy(f_student.dj.courses_id[i].date,readding_temp.dj.courses_id[i].date);
          //  printf("%f",readding_temp.dj.courses_id[i].gpv_value);
            if(readding_temp.dj.courses_id[i].gpv_value < 0.000001)
            {
                printf("\nCourse Name : %s",f_student.dj.courses_id[i].couse_id);
                printf("\nEnter GPV value : ");
                scanf("%f",&readding_temp.dj.courses_id[i].gpv_value);
                f_student.dj.courses_id[i].gpv_value = readding_temp.dj.courses_id[i].gpv_value;
            }
        }
        printf("\n\t--- Inserted ---");
    }
    fwrite(&readding_temp,sizeof(struct u_course),1,temp_file);


 }
     fclose(temp_file);
    fclose(student_details12);
 if(found)
 {
    temp_file = fopen("all_temp_details.txt","r");
    student_details12 = fopen("student_detail.txt","w");

    while(fread(&redding_2,sizeof(struct u_course),1,temp_file))
    {
        fwrite(&redding_2,sizeof(struct u_course),1,student_details12);

    }

    fclose(temp_file);
    fclose(student_details12);


 }
 else{

    printf("Cannot be Found Your Index Number");
 }


return 0;
}

int new_student()
{
        student_details = fopen("student_detail.txt","a+");
        char my_nm[40];
        char temp[15];
        int j;
        int countting = 0;
        fflush(stdin);
        printf("Enter Your Full Name : ");
        fgets(f_student.dj.st_name,20,stdin);
        f_student.dj.st_name[strlen(f_student.dj.st_name)-1]='\0';
      //  f_student.dj.st_name = my_nm;
       // printf("My Name is : %s",f_student.dj.st_name);
        printf("Enter Your Index Number : ");
        fgets(f_student.dj.st_index,20,stdin);
        f_student.dj.st_index[strlen(f_student.dj.st_index)-1]='\0';
       // f_student.dj.st_index = my_nm;
       // printf("My Index is %s : ",f_student.dj.st_index);
        printf("Enter Your Department : ");
        fgets(f_student.dj.st_department,20,stdin);
        f_student.dj.st_department[strlen(f_student.dj.st_department)-1]='\0';
     //   f_student.dj.st_department = my_nm;


     //file handling things 
     c_testting();

     do
     {
        
        printf("\nIf you want to Register new course : (Y/N)");
        scanf("%s",&my_nm);
        j=(!(strcmp(my_nm,"Y")));
        if((j))
        {
            printf("Enter The Course Code : ");
            scanf("%s",&f_student.dj.courses_id[countting].couse_id);
            strcpy(f_student.dj.courses_id[countting].date,__DATE__);
            countting++;
        }
        else{

            printf("\n\t\t----- Inserted Succerfully -----\n");

        }
        
        
     } while ((j));
     
     f_student.dj.number_of_courses  = (countting-1);

 
  /*   for(int i = 0; i < 2; i++)
    {
        //fgetc(stdin);
        printf("\nEnter coursw : ");
        scanf("%s",&f_student.dj.courses_id[i].couse_id);
         
      //  printf("My course %s",f_student.dj.courses_id[i].couse_id);
    } */
 
        fwrite(&f_student,sizeof(struct u_course),1,student_details);

        printf("\nName : %s",f_student.dj.st_name); 
        printf("\nDepartment : %s",f_student.dj.st_department);
        printf("\nIndex : %s",f_student.dj.st_index);
        printf("\n-------------------------------------------------------\n");
        printf("course Id");
        printf("\t\tDate");
        


        for(int j = 0; j <= f_student.dj.number_of_courses; j++)
        {

            printf("\n%s",f_student.dj.courses_id[j].couse_id);
            printf("\t\t\t%s",f_student.dj.courses_id[j].date);

        }
        printf("\n-------------------------------------------------------\n");
        fclose(student_details);
       
         
    return 0;
}

void new_course_adding()
{
        char save[10];
        course_details = fopen("scourse_detail.txt","a+");
        fflush(stdin);
        printf("Enter Course Code : ");
        fgets(c_registation.new_course_id,20,stdin);
        c_registation.new_course_id[strlen(c_registation.new_course_id)-1]='\0';
        printf("Enter Course Name : ");
        fgets(c_registation.new_course_name,20,stdin);
        c_registation.new_course_name[strlen(c_registation.new_course_name)-1]='\0';
        printf("Enter Course Credits : ");
        fgets(c_registation.new_creadit_value,20,stdin);
        c_registation.new_creadit_value[strlen(c_registation.new_creadit_value)-1]='\0';

        printf("\nDo You want to save it ? (Y/N)");
        fgets(save,20,stdin);
        save[strlen(save)-1]='\0';
        int condition = strcmp(save,"Y");
        if(!(condition))
        {
             fwrite(&c_registation,sizeof(struct u_course),1,course_details);
             printf("\n\n\t----- Saved -----");

            printf("\n\nCourse Code : %s",c_registation.new_course_id);
            printf("\nCourse Name : %s",c_registation.new_course_name);
            printf("\nCourse Credits : %s",c_registation.new_creadit_value);

        }
        else{

            printf("\n\t----- Could not Be Saved -----");
        }




        fclose(student_details);
}

void testting()
{
   // printf("Testting page");
    struct u_course readding;
    FILE *student_details1 = fopen("student_detail.txt","r");
    while(fread(&readding,sizeof(struct u_course),1,student_details1))
    {
        printf("\n-------------------------------------------------------\n");      
        printf("\nStudent name : %s",readding.dj.st_name);
        printf("\nStudent Index : %s",readding.dj.st_index);
        printf("\ndepartmetnt: %s",readding.dj.st_department);
        printf("\n-------------------------------------------------------\n");  
          printf("Course ID");
          printf("\tGPV");  

        for(int i = 0; i <= readding.dj.number_of_courses; i++)
        {
            printf("\n%s",readding.dj.courses_id[i].couse_id);
            printf("\t\t %.3f",readding.dj.courses_id[i].gpv_value);
        } 
        printf("\n-------------------------------------------------------\n");  
        printf("\n\n");
     /*    printf("\nStudent name : %s",readding.dj.st_name);
        printf("\nStudent Index : %s",readding.dj.st_index); */
        
    }

    fclose(student_details1);


}

void c_testting()
{
    struct u_course c_reading;
    course_details = fopen("scourse_detail.txt","r");
    
    printf("\n\n\t\t-------- Couse Details --------\n");

    printf("\nCourse_Id");
    printf("\tCreadits");
    printf("\t\tCourse Name\n");

        while(fread(&c_reading,sizeof(struct u_course),1,course_details))
    {
      //  printf("\nTestting page");  

        printf("\n%s",c_reading.new_course_id);   
        printf("\t\t\t%s",c_reading.new_creadit_value); 
        printf("\t\t%s",c_reading.new_course_name); 
         
        
        /* for(int i = 0; i < 2; i++)
        {
            printf("\nCourse %s",readding.dj.courses_id[i].couse_id);
        } */
       
        
    }
    printf("\n-------------------------------------------------------");

    fclose(course_details);



}

void c_testting2()
{
    struct u_course ss;
    FILE *temp_file1 = fopen("my_temp_file.txt","r");
   // printf("Testting page");
    while(fread(&ss,sizeof(struct u_course),1,temp_file1))
    {
      //  printf("Testting page");      
        printf("\nStudent name : %s",ss.dj.st_name);
        printf("\nStudent Index : %s",ss.dj.st_index);
      //  printf("\nCourse %d",ss.dj.number_of_courses);
        for(int i = 0; i < ss.dj.number_of_courses; i++)
        {
             
            printf("\nCourse %s",ss.dj.courses_id[i].couse_id);
            printf("\nCourse %s",ss.dj.courses_id[i].date);
            //printf("\nCourse %d",ss.dj.number_of_courses);
        } 
     /*    printf("\nStudent name : %s",readding.dj.st_name);
        printf("\nStudent Index : %s",readding.dj.st_index); */
        
    }

}

void update_curicular_data()
{
    int verify;
    int found = 0;
    struct u_course updatting_data;
    struct u_course updatting;
    char name[20];
    FILE *old;
    old = fopen("student_detail.txt","r");
    temp_file = fopen("updatting.txt","w");
    char index_num[20];
    fflush(stdin);
    printf("Enter The Index Number : ");
    fgets(index_num,20,stdin);
    index_num[strlen(index_num)-1]='\0';



    
 while(fread(&updatting_data,sizeof(struct u_course),1,old))
 {
    verify = strcmp(index_num,updatting_data.dj.st_index);
    if(!(verify))
    {
        found = 1;
        printf("Enter Your New Name : ");
        strcpy(updatting_data.dj.st_index,updatting_data.dj.st_index);
      //  strcpy(f_student.dj.st_name,updatting_data.dj.st_name);
        fgets(name,20,stdin);
        name[strlen(name)-1]='\0';
        strcpy(updatting_data.dj.st_name,name);
        printf("%s",updatting_data.dj.st_name);
        printf("Enter Your New Department : ");
       // strcpy(f_student.dj.st_department,updatting_data.dj.st_department);
        fgets(updatting_data.dj.st_department,20,stdin);
        updatting_data.dj.st_department[strlen(updatting_data.dj.st_department)-1]='\0';
        updatting_data.dj.number_of_courses = updatting_data.dj.number_of_courses;

        for(int i = 0; i <= updatting_data.dj.number_of_courses; i++)
        {
            strcpy(updatting_data.dj.courses_id[i].couse_id,updatting_data.dj.courses_id[i].couse_id);
            strcpy(updatting_data.dj.courses_id[i].date,updatting_data.dj.courses_id[i].date);
            updatting_data.dj.courses_id[i].gpv_value = updatting_data.dj.courses_id[i].gpv_value;
        }

    }
    fwrite(&updatting_data,sizeof(struct u_course),1,temp_file);
}
    


    fclose(temp_file);
    fclose(old);


    if(found)
    {
        
    temp_file = fopen("updatting.txt","r");
    old = fopen("student_detail.txt","w");

    while(fread(&updatting_data,sizeof(struct u_course),1,temp_file))
    {
         
        fwrite(&updatting_data,sizeof(struct u_course),1,old);

    }
    fclose(temp_file);
    fclose(old);

 }

 }



void update_course_details()
{

    struct u_course update_course;
    FILE *old;
    old = fopen("student_detail.txt","r");
    temp_file = fopen("updatting_course.txt","w");
    char index_num [20];
    char my_num[5];
    int found = 0,j = 0,countting = 0;
    fflush(stdin);
    printf("Enter The Index Number : ");
    fgets(index_num,20,stdin);
    index_num[strlen(index_num)-1]='\0';


    while(fread(&update_course,sizeof(struct u_course),1,old))
    {
        int k = strcmp(index_num,update_course.dj.st_index);
        if(!(k))
        {
            found = 1;
            strcpy(update_course.dj.st_index,update_course.dj.st_index);
            strcpy(update_course.dj.st_name,update_course.dj.st_name);
            strcpy(update_course.dj.st_department,update_course.dj.st_department);


           c_testting();
              do
         {
        
        printf("\nIf you want to Register new course : (Y/N)");
        scanf("%s",&my_num);
        j=(!(strcmp(my_num,"Y")));
        if((j))
        {
            printf("\nEnter The Course ID : ");
            scanf("%s",&update_course.dj.courses_id[countting].couse_id);
            strcpy(update_course.dj.courses_id[countting].date,__DATE__);
            countting++;
        }
        else{

            printf("\n\n----- Inserted Succerfully -----");

        }
        
        
     } while ((j));
     
     update_course.dj.number_of_courses  = (countting-1);

        }
 
     fwrite(&update_course,sizeof(struct u_course),1,temp_file);

    }

    fclose(old);
    fclose(temp_file);
 
    if(found)
    {
        
    temp_file = fopen("updatting_course.txt","r");
    old = fopen("student_detail.txt","w");

    while(fread(&update_course,sizeof(struct u_course),1,temp_file))
    {
         
        fwrite(&update_course,sizeof(struct u_course),1,old);

    }
    fclose(temp_file);
    fclose(old);

 }

}



void update_gpv()
{
    struct u_course readding_temp;
    struct u_course redding_2;
    char temp_name[20];
    int k;
    int found = 0;
    FILE *student_details111;
    FILE *student_details12 = fopen("student_detail.txt","r");
    temp_file = fopen("all_temp_details.txt","w");
    fflush(stdin);
    printf("Enter Index Number : ");
    fgets(temp_name,20,stdin);
    temp_name[strlen(temp_name)-1]='\0';

    
 while(fread(&readding_temp,sizeof(struct u_course),1,student_details12))
 {
    k = strcmp(temp_name,readding_temp.dj.st_index);
    if(!(k))
    {
        found = 1;
        strcpy(f_student.dj.st_index,readding_temp.dj.st_index);
        strcpy(f_student.dj.st_name,readding_temp.dj.st_name);
        strcpy(f_student.dj.st_department,readding_temp.dj.st_department);
        f_student.dj.number_of_courses = readding_temp.dj.number_of_courses;

        for(int i = 0; i <= f_student.dj.number_of_courses; i++)
        {
            strcpy(f_student.dj.courses_id[i].couse_id,readding_temp.dj.courses_id[i].couse_id);
            strcpy(f_student.dj.courses_id[i].date,readding_temp.dj.courses_id[i].date);

                printf("\nCourse Name : %s",f_student.dj.courses_id[i].couse_id);
                printf("\nEnter GPV value : ");
                scanf("%f",&readding_temp.dj.courses_id[i].gpv_value);
                f_student.dj.courses_id[i].gpv_value = readding_temp.dj.courses_id[i].gpv_value;
            
        }
    }
    fwrite(&readding_temp,sizeof(struct u_course),1,temp_file);


 }
     fclose(temp_file);
    fclose(student_details12);
 if(found)
 {
    temp_file = fopen("all_temp_details.txt","r");
    student_details12 = fopen("student_detail.txt","w");

    while(fread(&redding_2,sizeof(struct u_course),1,temp_file))
    {
        fwrite(&redding_2,sizeof(struct u_course),1,student_details12);

    }
    fclose(temp_file);
    fclose(student_details12);

 }
}


void delete_st_details()
{
    char temp_name[40];
    FILE *delete_details;
    struct u_course redding;
    struct u_course tmp_write;
   // int temp_conn;
    delete_details = fopen("student_detail.txt","r");
    temp_file = fopen("all_temp_details.txt","w");

    if(delete_details == NULL)
    {
        printf("Could not be opened The file");
        exit(0);
    }
    else
    {

    

    fflush(stdin);
    printf("Enter Index Number : ");
    fgets(temp_name,20,stdin);
    temp_name[strlen(temp_name)-1]='\0';

     while(fread(&redding,sizeof(struct u_course),1,delete_details))
     {
       int temp_conn = strcmp(temp_name,redding.dj.st_index);
        if(!(temp_conn))
        {
            printf("----DELECTED SUCCERFULLY-----");
        }
        else
        {
              strcpy(tmp_write.dj.st_index,redding.dj.st_index);
              strcpy(tmp_write.dj.st_name,redding.dj.st_name);
              strcpy(tmp_write.dj.st_department,redding.dj.st_department);
              tmp_write.dj.number_of_courses = redding.dj.number_of_courses;
              for(int i = 0; i <= redding.dj.number_of_courses; i++)
              {
                strcpy(tmp_write.dj.courses_id[i].couse_id,redding.dj.courses_id[i].couse_id);
                strcpy(tmp_write.dj.courses_id[i].date,redding.dj.courses_id[i].date);
                tmp_write.dj.courses_id[i].gpv_value = redding.dj.courses_id[i].gpv_value;
              }
            fwrite(&tmp_write,sizeof(struct u_course),1,temp_file);

        }

     }

    fclose(temp_file);
    fclose(delete_details);

    delete_details = fopen("student_detail.txt","w");
    temp_file = fopen("all_temp_details.txt","r");

    while(fread(&tmp_write,sizeof(struct u_course),1,temp_file))
    {

        fwrite(&tmp_write,sizeof(struct u_course),1,delete_details);

    }


    fclose(temp_file);
    fclose(delete_details);
    }


}
     

void all_details()
{
    FILE *st_detail;
    FILE *c_details;
    st_detail = fopen("student_detail.txt","r");   
    struct u_course course_del;
    struct u_course reading_details;
    printf("\n\n\t\t========= Students Details =========");
    while(fread(&reading_details,sizeof(struct u_course),1,st_detail))
    {
         
            
            printf("\n\nStudent Name : %s",reading_details.dj.st_name);
            printf("\nIndex Number : %s",reading_details.dj.st_index);
            printf("\nDepartment : %s",reading_details.dj.st_department);
            printf("\n--------------------------------------------------------");
            printf("\nCourse Id");
            printf("\tCourse Name");
            printf("\t\tGPV");
            printf("\tGrade\n\n"); 
            for(int i = 0; i <= reading_details.dj.number_of_courses; i++)
            {
              c_details = fopen("scourse_detail.txt","r");
                 printf("%s",reading_details.dj.courses_id[i].couse_id);
                while(fread(&course_del,sizeof(struct u_course),1,c_details))
                {
                    int p1 = strcmp(reading_details.dj.courses_id[i].couse_id,course_del.new_course_id);
                    if(!(p1))
                    {
                         printf("\t\t%s",course_del.new_course_name);
                        
                    }
                 
                } 
                fclose(c_details);
                printf("\t\t%.2f",reading_details.dj.courses_id[i].gpv_value);
                if(reading_details.dj.courses_id[i].gpv_value >= 4.000000)
                {
                    printf("\t%s\n","A");
                }
                else if(3.910000 >= reading_details.dj.courses_id[i].gpv_value && 3.000000 <= reading_details.dj.courses_id[i].gpv_value)
                {
                    printf("\t%s\n","B");

                }
                else if (2.91 > reading_details.dj.courses_id[i].gpv_value & 2.500000 <= reading_details.dj.courses_id[i].gpv_value )
                {
                    printf("\t%s\n","C");
                     
                }
                else if(2.400000 >= reading_details.dj.courses_id[i].gpv_value && 1.500000 <= reading_details.dj.courses_id[i].gpv_value)
                {
                    printf("\t%s\n","D");
                }
                else{
                    printf("\t%s\n","E");
                }   
            }
        }
    fclose(st_detail);
    printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n ");

}

