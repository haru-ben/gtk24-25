#include"C:\Users\hp\Documents\gtkprojet\Les_Macros\ScrollBar.h"

int main(int argc, char *argv[]) {

   Program_Begin(argc,argv);

    // Création d'une structure Fenetre
    Fenetre maFenetre;
   

    set_window_type(&maFenetre,TRUE);
   
     set_window_decorate(&maFenetre,FALSE);

    // Initialisation des propriétés de la fenêtre
    maFenetre.Title = "Test des fonctions de fenêtre";
    maFenetre.Resizable = TRUE;

    // Définir le titre de la fenêtre
    gtk_window_set_title(GTK_WINDOW(maFenetre.Wind), maFenetre.Title);

    // Tester la fonction Definir_Taille
    Definir_Taille(&maFenetre, 1000,600);

    
    // Tester la fonction Definir_Redimensionnable
    Definir_Redimensionnable(&maFenetre, TRUE);
    


    

    // Tester la fonction Definir_Position_Connu
    Definir_Position_Connu(&maFenetre, Pos_Centre); // Positionner au centre
 
   
    // Créer et initialiser un ScrollBar
    ScrollBar *scroll = InitScrollBar();

    // Ajouter le ScrollBar à la fenêtre
    Ajouter_Scrollbar(&maFenetre, scroll);

    // Modifier les ajustements (test vertical)
    Modifier_V_Ajustments(scroll, 100.0, 10.0, 10.0, 20.0);

    // Modifier les ajustements (test horizontal)
   Modifier_H_Ajustments(scroll, 200.0, 20.0, 10.0, 20.0);

    // Changer la politique de défilement horizontale (test)
    //ChangerPolitiqueHorizontale(scroll, GTK_POLICY_NEVER);

    // Changer la politique de défilement verticale (test)
   // ChangerPolitiqueVerticale(scroll, GTK_POLICY_ALWAYS);
  
    ScrollToEnd(scroll);

    // Connecter le signal de fermeture de la fenêtre
    g_signal_connect(maFenetre.Wind, "destroy", G_CALLBACK(gtk_main_quit), NULL);
   // Fenetre_Set_BackGround_Image(&maFenetre,"C:/Users/hp/Pictures/images (1).jpg");
    Afficher_Fenetre(&maFenetre);
                  

    // Démarrer la boucle principale GTK
    gtk_main();

    return 0;
}
 /*GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);


   gtk_container_add(GTK_CONTAINER(maFenetre.Wind), scrolled_window);
    GtkWidget *text_view = gtk_text_view_new();
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

    // Texte long pour tester la barre de défilement
    const gchar *text = "Ceci est un texte long\n"
                        "Pour tester la barre de défilement.\n"
                        "Faites défiler le texte pour voir la scrollbar en action.\n\n";
    gtk_text_buffer_set_text(buffer, text, -1);
   

    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);

     gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);

    GtkAdjustment *adjustment = gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW(scrolled_window));
    gtk_adjustment_set_value(adjustment, 0.25);*/


