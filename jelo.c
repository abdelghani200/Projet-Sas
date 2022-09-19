#include<stdio.h>
#include<string.h>
#include<windows.h>
#define taille 100

typedef struct{
	char nom[30];
	float prix;
	float quantite;
	int code;
}Produit;



static int nb;
Produit temp;

void Ajouter_produit(Produit *p,int index){

	printf("\t\t\tDonner les informations du nouveau produit:\n");
	printf("Saisir le nom du produit %d:",index+1);
	scanf("%s",p->nom);
	printf("Saisir le code du produit %d:",index+1);
	scanf("%d",&p->code);
	printf("Saisir le prix du produit %d:",index+1);
	scanf("%f",&p->prix);
	printf("Saisir le quantite du produit %d:",index+1);
	scanf("%f",&p->quantite);
}

void Ajouter_produits(Produit P[]){

	int i;
	printf("Veuillez saisir le nombre des produits ajouter:");
	scanf("%d",&nb);	
	for(i=0;i<nb;i++){
		Ajouter_produit(&P[i],i);
	}
}


void afficher_produits(Produit p[])
{ 
	int i,j;  
    float prixTtc=p[i].prix+15;
	printf ("---------------------------------------------------------------------------------------------------------------\n");
	printf("  Nom\t\t\tPrix\t\t\tPrixTTC\t\t\n");
	printf("---------------------------------------------------------------------------------------------------------------\n");
		for(i=0;i<nb;i++)
		{
			
				printf ("%s\t\t%d\t\t%f\t\t%f\t\t\n",p[i].nom,p[i].code,p[i].prix,prixTtc);	
			
		}
		
}

void suppProduit(Produit p[]){
	int cd;
	printf("\nDonner un code : ");
	scanf("%d",&cd);
	int i;
	int j;
	int trouve = 0;
	for(i=0;i<nb;i++){
			if(p[i].code==cd){
				for(j=i;j<nb;j++){
					p[j]=p[j+1];
				}
				nb=nb-1;
				printf("\nSuppression effectuer ! \n");
			
			}else{
			  printf("Impossible de supprimer le produit %s de code %s \n",p[i].nom,p[i].code);
			}
			trouve = 1;
	}	
	if (trouve == 0)
		printf("\nReference introuvable!\n");
	
}



void afficher_produits2(Produit p[])
{ 
	int i,j;  

	printf ("---------------------------------------------------------------------------------------------------------------\n");
	printf("  Nom\t\tCode\t\tPrix\t\tQuantite\t\t\n");
	printf("---------------------------------------------------------------------------------------------------------------\n");
		for(i=0;i<nb;i++)
		{
			if(p[i].quantite < 3){
				printf ("%s\t\t%d\t\t%f\t\t%f\t\t\n",p[i].nom,p[i].code,p[i].prix,p[i].quantite);	
			}
		}
		
}


void tri_prix(Produit p[]){
	int i,j;
	for(i=0;i<nb;i++){
		for(j=0;j<nb;j++){
			if(strcmp(p[i].nom,p[j].nom)<0){
				temp.prix=p[i].prix;
				p[i].prix=p[j].prix;
				p[j].prix=temp.prix;
			}
		}
	}
	float prixTtc;
    printf ("---------------------------------------------------------------------------------------------------------------\n");
	printf("  Nom\t\t\tPrix\t\t\tPrixTTC\t\t\n");
	printf("---------------------------------------------------------------------------------------------------------------\n");
		for(i=0;i<nb;i++)
		{
			    prixTtc=p[i].prix+15;
				printf ("%s\t\t%f\t\t%f\t\t\n",p[i].nom,p[i].prix,prixTtc);	
			
		}
}



void tri_nom(Produit p[]){
	int i,j;
	for(i=0;i<nb;i++){
		for(j=i+1;j<nb;j++){
			if(strcmp(p[i].nom,p[j].nom)<0){
				strcpy(temp.nom,p[i].nom);
				strcpy(p[i].nom,p[j].nom);
				strcpy(p[j].nom,temp.nom);
			}
		}
	}
	float prixTtc;
    printf ("+-------------------------------+--------------------+----------------+--------------------------------+\n");
	printf("  Nom\t\t\tPrix\t\t\tPrixTTC\t\t\n");
    printf ("+-------------------------------+--------------------+----------------+--------------------------------+\n");

		for(i=0;i<nb;i++)
		{
			    prixTtc=p[i].prix+15;
				printf ("%s\t\t%f\t\t%f\t\t\n",p[i].nom,p[i].prix,prixTtc);	
			
		}
}



void Recherche_code(Produit P[]){
	int i,cod;
	do{
		printf("Donner le code du produit : ");
		scanf("%d",&cod);
	}while(cod<=0);
	int trouve=0;
	printf ("----------------------------------------------------------------------------------------\n");
	printf(" Nom\t\tCode\t\tPrix\t\tQuantite\t\t\n");
	printf("-----------------------------------------------------------------------------------------\n");
		for(i=0;i<nb;i++)
		{	if(P[i].code==cod){
			printf ("%s\t\t%d\t\t%f\t\t%f\t\t\n",P[i].nom,P[i].code,P[i].prix,P[i].quantite);	
			trouve=1;
		}	
		}
	if (trouve==0){
		printf("\nAucun medicament en rupture.\n");
	}
}

void Recherche_Quantite(Produit p[]){
	float quant;
	do{
		printf("Donner la quantite du produit : ");
		scanf("%d",&quant);
	}while(quant<=0);
	int i;
	int trouve=0;
	printf ("------------------------------------------------------------------------\n");
	printf("  Nom\t\tCode\t\tPrix\t\tQuantite\t\t\n");
	printf("-------------------------------------------------------------------------\n");
		for(i=0;i<nb;i++)
		{	
			if(p[i].quantite==quant){
				    printf ("%s\t\t%d\t\t%f\t\t%f\t\t\n",p[i].nom,p[i].code,p[i].prix,p[i].quantite);	
					trouve=1;
				}		
		}
		printf("\n\n");	
		
	if(trouve==0){
		printf("\nMedicament inconnu!\n");
	}
}




int Recherche_coder(Produit P[]){
	int i,cod;
	do{
		printf("Donner le code du produit : ");
		scanf("%d",&cod);
	}while(cod<=0);
	int trouve=0;
	printf ("----------------------------------------------------------------------------------------\n");
	printf(" Nom\t\tCode\t\tPrix\t\tQuantite\t\t\n");
	printf("-----------------------------------------------------------------------------------------\n");
		for(i=0;i<nb;i++)
		{	if(P[i].code==cod){
			printf ("%s\t\t%d\t\t%f\t\t%f\t\t\n",P[i].nom,P[i].code,P[i].prix,P[i].quantite);
			
			trouve=1;
			return cod;
		}	
		}
	if (trouve==0){
		printf("\nAucun medicament en rupture.\n");
		return -1;
	}
}


void Acheter_prod(Produit P[]){
	int i,cod,t=0;
	float quant;
	
    cod=Recherche_coder(P);
    if(cod!=-1){
    printf("Donner la quantite du produit  que tu veux : ");
	scanf("%f",&quant);
	
	for(i=0;i<nb;i++){	
			
		if(P[i].code==cod && P[i].quantite>=quant){
			
			P[i].quantite -= quant;
			
			printf ("%s\t\t%d\t\t%f\t\t%f\t\t\n",P[i].nom,P[i].code,P[i].prix,P[i].quantite);		
			printf("\n\n");
			t=1;
		}			
    }
    if(t==0){
		printf("Votre commande ne se trouve pas!!");
		
	}
}
}


void Alimenter_stock(Produit P[]){
    int i,cod,t=0;
	float quant;
	
    cod=Recherche_coder(P);
    if(cod!=-1){
    printf("Donner la quantite du produit  que tu veux : ");
	scanf("%f",&quant);
	
	for(i=0;i<nb;i++){	
			
		if(P[i].code==cod){
			
			P[i].quantite=P[i].quantite+quant;
			
			printf ("%s\t\t%d\t\t%f\t\t%f\t\t\n",P[i].nom,P[i].code,P[i].prix,P[i].quantite);		
			printf("\n\n");
			t=1;
		}			
    }
    if(t==0){
		printf("Votre commande ne se trouve pas!!");
		
	}
}	
}







int main(){

	Produit p[10];
	int choix,index;
	index=0;
	
	do
	{

		do
		{
		printf("\t\t\t\t _______________________________________________\n");
		printf("\t\t\t\t| -------- Base de donnees de pharmacie --------| \n");
		printf("\t\t\t\t| 1  : Ajouter un nouveau produit               | \n");
		printf("\t\t\t\t| 2  : Ajouter plusieurs nouveaux produits      | \n");
		printf("\t\t\t\t| 3  : Afficher les produits                    | \n");
		printf("\t\t\t\t| 4  : Afficher les produits dont quantite < 3  | \n");
		printf("\t\t\t\t| 5  : Rechercher des produits par code et Qtt  | \n");
		printf("\t\t\t\t| 6  : Supprimer un produit                     | \n");
		printf("\t\t\t\t| 7  : Acheter un produit                       | \n");
		printf("\t\t\t\t| 8  : Alimenter_stock                          | \n");
		printf("\t\t\t\t| 9  : Quitter le programe                      | \n");
		printf("\t\t\t\t|_______________________________________________| \n");
		printf("\n");
			
		printf("Choisir un choix:");
		scanf("%d",&choix);
			
     	}while(choix<1 || choix>9);

		switch(choix)
		{
			case 1 : Ajouter_produit(p,index);break;
			case 2 : Ajouter_produits(p);break;
			case 3 : 
			printf("\t\t\t\t|____________________| \n");
			printf("\t\t\t\t| 1  : Par Ordre Prix| \n");
		    printf("\t\t\t\t| 2  : Par Ordre Nom | \n");	
			printf("\t\t\t\t|____________________| \n");
		    printf("\n");
		    printf("Donner votre choix:");
	        scanf("%d",&choix);
	        if(choix==1){
	    	tri_prix(p);break;
		    }
		    else if(choix==2){
			tri_nom(p);break;
		    }
		    case 4 : afficher_produits2(p);break;
			case 5 :
			printf("\t\t\t\t|_____________________________| \n");
			printf("\t\t\t\t| 1  : Rechercher Par Code    | \n");
		    printf("\t\t\t\t| 2  : Rechercher Par Quantite| \n");	
			printf("\t\t\t\t|_____________________________| \n");
		    printf("\n");	
			printf("Donner votre choix:");	
	        scanf("%d",&choix);
	        if(choix==1){
	    	Recherche_code(p);break;
	    	
		    }
		    else if(choix==2){
			Recherche_Quantite(p);break;
			
		    }	
		    case 6 : suppProduit(p);break;
		    case 7 : Acheter_prod(p); break;
		    case 8 : Alimenter_stock(p);break;
		             
			default : break;
		}

	}while(choix!=9);

	return 0;
}












