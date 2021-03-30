#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {
    printf("%s:\n",t.name);
    for(int i = 0; i<t.offices_count;i++){
        
        printf("\t%d:\n",i);
        for(int p=0;p<(t.offices+i)->packages_count;p++){
            printf("\t\t%s\n",(((t.offices+i)->packages+p)->id));
        } 
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {	
    int package_count_in_source_towns_postoffice = 0;
    for(int i=0;i<source->offices_count;i++){
        if(i==source_office_index){
            package_count_in_source_towns_postoffice = ((source->offices)+i)->packages_count;
        }
    }
    

   
   for(int h=0;h<package_count_in_source_towns_postoffice;h++){
       if(((((((source->offices)+source_office_index)->packages)+h)->weight)>=(((target->offices)+target_office_index)->min_weight)) && ((((((source->offices)+source_office_index)->packages)+h)->weight)<=(((target->offices)+target_office_index)->max_weight))){

        
           ((target->offices)+target_office_index)->packages_count++;
           
           ((target->offices)+target_office_index)->packages = realloc(((target->offices)+target_office_index)->packages, sizeof(package) * ((target->offices)+target_office_index)->packages_count); 
           
           int temp = ((target->offices)+target_office_index)->packages_count-1;
           
           *(((target->offices+target_office_index)->packages)+temp) = *((((source->offices)+source_office_index)->packages)+h); 
           
           ((source->offices)+source_office_index)->packages_count--;
   
       }
   }  
}

town town_with_most_packages(town* towns, int towns_count) {
    int index_of_town_with_max_no_of_packages = 0;
    int max_package_quantity = 0;
    int count_total_packages_per_town = 0;
    int arr_per_town_total_packages[towns_count];
    
    for(int i=0;i<towns_count;i++){
        count_total_packages_per_town = 0;
        for(int j=0;j<(towns+i)->offices_count;j++){
            count_total_packages_per_town += (((towns+i)->offices)+j)->packages_count;
        }
        arr_per_town_total_packages[i]  = count_total_packages_per_town;
    }
       //Find max_quantity_index in arr of total town packages
    int loc=0;
    for(int k=1;k<towns_count;k++){
       
            if(arr_per_town_total_packages[loc]<arr_per_town_total_packages[k]){
                loc=k;
                index_of_town_with_max_no_of_packages = k;
            }  
    }  
  return *(towns+index_of_town_with_max_no_of_packages);  
}

town* find_town(town* towns, int towns_count, char* name) {
    int index_of_town = 0;
    for(int i=0;i<towns_count;i++){
        if(strcmp(name,(towns+i)->name)==0){
            index_of_town = i;
            break;
        }
    }
    return towns+index_of_town;
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}
