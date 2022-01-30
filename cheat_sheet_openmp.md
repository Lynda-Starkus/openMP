## Cheat sheet openMP :
### Modèle d'exécution :
> openMP est une interface de programmation qui offre des directives et fonctions de parallèlisation et synchronisation.
> Elle suit le modèle fork-join 
### Création de région parallèle :
> #progrma omp parallel [clause, ...]{}

### Les clauses :
> - private(list of private variables)
> - shared(list of shared variables)
> - default(private or shared or none)
> - num_threads(nombre_de_threads)
> - if(condition de parallèlisation)
> - for
> - master //que le thread maitre qui exécute le bloc
> - sections / section //des thread différents peuvent exécuter les instructions d'une région parallèle


### Les clauses pour #pragme omp for 
> - schedule(type : static oe dynamic, chunk_size)
> - collapse(number of boucles for )
> - nowait //le thread qui termine n'attend pas les autres
> - reduction(opérateur:variable de sortie) 

### Les clauses de synchronisation :
> - pragma omp barrier //tous les threads se rejoignent quand ils trouvent cette directive
> - pragme omp critical //un thread execute le bloc à la fois
> - pragme omp atomic //pareil que critical mais porte sur une seule instruction 

### Fonctions utiles :
> - omp_get_thread_num();
> - omp_get_num_threads();
> - omp_get_wtime();
