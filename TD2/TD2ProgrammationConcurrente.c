#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <String.h>

pthread_t cree_tache(void * (*start_routine)(void *), void * arg){
    pthread_t id;
    int erreur;
    erreur = pthread_create( &id, NULL, start_routine, arg);
    if (erreur != 0){
        perror( "Echec creation de tâche Posix" );
        exit(-1);
    } 
 return id;
}

void *affiche(void *arg ){
    const char *chaine;
    chaine = (char*) arg;
    puts(chaine);
    return 0;
    
}

int main(){
  
    pthread_t id;
    pthread_t tache_1;
    pthread_t tache_2;
    pthread_t tache_3;
    pthread_t tache_4;

   const char *const chaine1 = "Souvent, pour s amuser, les hommes d’equipage";
   tache_1= cree_tache( affiche, (void*)  chaine1);
   // une des solutions pour attendre que la termine et donc assurer l'affichage et aussi l'ordre
   //pthread_join( tache_1, NULL); 
   // terminer proprement la tache 
   //pthread_cancel(tache_1); 
   //ou bien suspend l'exécution de la tâche Posix en terminant ses instructions 
   pthread_exit;

   
   const char *const chaine2 ="Prennent des goelands, vastes oiseaux des mers,";
   tache_2= cree_tache( affiche, (void*)  chaine2);
    pthread_join( tache_2, NULL);

   const char *const chaine3 ="Qui suivent, indolents compagnons de voyage,";
   tache_3= cree_tache( affiche, (void*)  chaine3);
    pthread_join( tache_3, NULL);//ATTENDRE QUE LA TACHE TERMINE POUR PASSER à L'AUTRE 

   const char *const chaine4 ="Le navire glissant sur les gouffres amers.";
   tache_4= cree_tache( affiche, (void*)  chaine4);
    pthread_join( tache_4, NULL);

      

}