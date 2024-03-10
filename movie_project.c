//Wap to make movies list.
#include<stdio.h>
#include<stdlib.h>
//making a structure to add movies details.
struct movie
{
    char movie_id[10];
    char movie_name[20];
    char movie_date[10];
    float movie_rating;
};
#define maxsize 100
int size;
struct movie movies[maxsize];
struct movie test[1];
//make a function to make new movies store.
void add_movies()
{
    int i;
    //enter how many movies you want to store.
    printf("enter the number of movie you want to store\n");
    scanf("%d",&size);
    //check if given size is out of limit or not .
    if(size>maxsize)
    {
        printf("Error !!!!!!\n");
        size=0;
    }
    else
    {
        int i;
        for(i=0;i<size;i++)
        {  
            //enter the movies details to store.
            //enter movie id.
            printf("Enter the movie id:\n");
            fflush(stdin);
            gets(movies[i].movie_id);
            //enter movie name.
            printf("Enter the movie name:\n");
            gets(movies[i].movie_name);
            //enter movie release date .
            printf("Enter the movie release date:\n");
            gets(movies[i].movie_date);
            //enter movie rating.
            printf("Enter the rating\n");
            scanf("%f",&movies[i].movie_rating);
        }
        printf("new movie created successfully !!!!!");
    }
}
//make function to show movies if present in list.
void display_movies()
{
    int i;
    //check if movies list is empty.
    if(size==0)
    {
        printf("No movies file !!!!!!\n");
    }
    else
    {
        //display movies.
        for(i=0;i<size;i++)
        {
            printf("%20s",movies[i].movie_name);
            printf("%15s",movies[i].movie_id);
            printf("%15s",movies[i].movie_date);
            printf("%14.1f",movies[i].movie_rating);
            printf("\n");
        }
    }
}
//make function to edit and insert movies.
void edit_insert_movies()
{
    int position,i,choice;
    //check if list has movies or not.
    if(position>size)
    {
        printf("No movies to edit !!!!!!\n");
    }
    else
    {
        //chose 1 or 2 to edit or insert.
        printf("enter choice \n 1. edit\n 2. insert\n");
        scanf("%d",&choice);
        switch(choice)
        {
            // 1 for edit movie name.
            case 1:
            if(size==0)
            {
                printf("Sorry no movies file !!!!!");
            }
            else
            {   
                int number_movies;
                printf("Enter how many movie you want to edit\n");
                scanf("%d",&number_movies);
                for(int j=1;i<number_movies;i++)
                {
                    printf("Enter the position in which you want to correct movie name:\n");
                    scanf("%d",&position);
                    for(i=position-1;;i++)
                    {
                        printf("Enter the correct movie name:\n");
                        fflush(stdin);
                        gets(movies[i].movie_name);
                        break;
                    }
                }
                printf("Movie name updated succesfully !!!!\n");
            }
            break;
            // 2 for insert new movie details.
            case 2:
            //check if there is any movie list to enter new movies.
            if(size==0)
            {
                printf("No movies file!!!!!\n");
            }
            else
            {
                //enter new movie details.
                char id[10];
                printf("Enter the position to insert movie details:\n");
                scanf("%d",&position);
                if(position>size)
                {
                    printf("invalid position !!!!!\n");
                }
                else
                {
                    for(i=size;i>=position;i--)
                    {
                        movies[i]=movies[i-1];
                    }
                    printf("Enter the movie id:\n");
                    fflush(stdin);
                    gets(test[0].movie_id);
                    for(int j=0;j<size;j++)
                    {
                        //also for checking that user do not use same movie id.
                        if(movies[j].movie_id==test[0].movie_id)
                        {  
                            printf("Enter the movie name:\n");
                            scanf("%s",movies[position-1].movie_name);
                            printf("Enter the movie release date:\n");
                            scanf("%s",movies[position-1].movie_date);
                            printf("Enter the rating\n");
                            scanf("%f",&movies[position-1].movie_rating);
                            printf("element inserted succesfully !!!!\n");
                        }
                       // else
                       // {
                       //     printf("Movie id exits!!!!!!\n");
                       // }
                        size++;
                        break;
                    }
                }
            }
        }
    }
}
//make a function to delete movies
void delete_movies()
{
    int i,movie_name;
    //check if there are movies in list to delete.
    if(size==0)
    {
        printf("No movies file !!!!!!\n");
    }
    else
    {
        //enter the movie name to delete its details.
        for(i=0;i<size;i++)
        {   
            printf("Enter the movie name to delete\n");
            scanf("%s",test[0].movie_name);
            int x=(movies[i].movie_name==test[0].movie_name)?1:0;
            if(x==1)
            {
                movies[i]=movies[i+1];
                printf("movie deleted succesfully \n");
            }
            else
            {
                printf("No movie exist with this name !!!!\n");
                printf("%s",test[0].movie_name);
            }
            size--;
            break;
        }
        //printf("movie deleted succesfully \n");
    }
}
//make a function to search movies.
void search_movies()
{
    int i;
    if(size==0)
    {
        printf("No movies file !!!!!\n");
    }
    else
    {
        int n;
        printf("Enter how many movies you want to search:\n");
        scanf("%d",&n);
        if(n>size)
        {
            printf("limit exceed!!!!");
        }
        else
        {   
            int x;
            printf("Enter the movie name to search\n");
            fflush(stdin);
            gets(test[0].movie_name);
            for(i=0;i<n;i++)
            {
                for(int j=0;j<size;j++)
                {   
                    if(movies[j].movie_name==test[0].movie_name)
                    {     
                        printf("%15s",movies[j].movie_name);
                        printf("%15s",movies[j].movie_id);
                        printf("%15s",movies[j].movie_date);
                        printf("%14.1f",movies[j].movie_rating);
                        printf("\n");
                        break;
                    }
                   // else
                   // {
                   //     printf("No movie found !!!!\n");
                   //     printf("%s\n%s\n",test.movie_name,movies[j].movie_name);
                  //      break;
                    //}
                }
            }
        }
    }
}
//MAIN FUNCTION BEGAINS
int main()
{  
    printf("-------------------------------WELCOME TO-------------------------------------\n");
    printf("--------------------------MOVIE MANAGAGENT SYSTEM------------------------------\n");
    while(1)
    {
        int choice;
        //choice numbers 
        //choose 1 for create new movie list.
        //choose 2 for display movie list.
        //choose 3 for edit and insert movies.
        //choose 4 for delete movies.
        //choose 5 for search movies.
        //choose 6 for exit.
        printf("1.Create new movies file\n");
        printf("2.Display the movie records\n");
        printf("3.Edit and insert movie\n");
        printf("4.Delete movie\n");
        printf("5.Search movie\n");
        printf("6.Exit\n");
        printf("Enter choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            add_movies();
            break;
            case 2:
            display_movies();
            break;
            case 3:
            edit_insert_movies();
            break;
            case 4:
            delete_movies();
            break;
            case 5:
            search_movies();
            break;
            case 6:
            break;
            default:
            printf("Invalid !!!!!");
        }
        printf("\n\n");
        system("pause");
        system("cls");
    }
}