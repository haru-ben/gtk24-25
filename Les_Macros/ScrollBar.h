#include"C:\Users\hp\Documents\gtkprojet\Les_Sdds\ScrollBar.h"
/*valeur de policy:
Les différentes politiques disponibles
GTK_POLICY_ALWAYS    // La barre de défilement est toujours visible
GTK_POLICY_NEVER     // La barre de défilement n'est jamais visible
GTK_POLICY_AUTOMATIC // La barre de défilement apparaît seulement si nécessaire
*/
// Fonction d'initialisation du scrollbar
  ScrollBar* InitScrollBar() {
    ScrollBar *scroll;
    scroll=(ScrollBar*) malloc(sizeof(ScrollBar));
    if(!scroll)
    {
        printf("erreur");
        exit(-1);
    }
    scroll->scroll_horizontal = TRUE;
    scroll->scroll_vertical = TRUE;
    scroll->h_policy = GTK_POLICY_ALWAYS;
    scroll->v_policy = GTK_POLICY_ALWAYS;
    scroll->h_value = 0.0;
    scroll->v_value = 0.0;
    scroll->h_step = 10.0;
    scroll->v_step = 10.0;
    scroll->scrolled_window = NULL;
    scroll->fils=NULL;
    scroll->parent=NULL;
    scroll->h_adjustment = NULL;
    scroll->v_adjustment = NULL;
    return((ScrollBar *)scroll);
}

void Ajouter_Scrollbar(Fenetre *F,ScrollBar *scroll) {
    // Création du GtkScrolledWindow
    scroll->scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    scroll->parent=F->Wind;
    // Définir les politiques de défilement
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll->scrolled_window), scroll->h_policy, scroll->v_policy);
    
    GtkWidget *text_view = gtk_text_view_new();
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    scroll->fils=text_view;
    // Ajout de beaucoup de texte pour forcer le défilement
    gtk_text_buffer_set_text(buffer,
        "Ligne 1\nLigne 2\nLigne 3\n..."  // Beaucoup de texte
        "Dernière ligne\n",
        -1);
    // Ajouter le "fils" (le widget à faire défiler) au GtkScrolledWindow
    if (scroll->fils) {
        gtk_container_add(GTK_CONTAINER(scroll->scrolled_window), scroll->fils);
    }

    // Ajouter le GtkScrolledWindow (contenant le "fils") au "parent"
    if (scroll->parent) {
        gtk_container_add(GTK_CONTAINER(scroll->parent), scroll->scrolled_window);
    }
}

void Modifier_V_Ajustments(ScrollBar *scroll, gdouble new_upper_limit, gdouble new_page_size, gdouble new_step_increment, gdouble new_page_increment)
{
    if (scroll->v_adjustment) {
        gdouble lower_limit_v = gtk_adjustment_get_lower(scroll->v_adjustment); // Limite inférieure de l'ajustement vertical
        // Reconfigurer l'ajustement vertical avec la nouvelle limite supérieure et la taille de la page
        gtk_adjustment_configure(scroll->v_adjustment,
                                 scroll->v_value,          // Position actuelle du défilement
                                 lower_limit_v,            // Limite inférieure
                                 new_upper_limit,          // Nouvelle limite supérieure
                                 new_step_increment,       // Incrément du défilement (pour les flèches)
                                 new_page_increment,       // Incrément pour la zone cliquable
                                 new_page_size);           // Nouvelle taille de la page (portion visible)
    }
}

void Modifier_H_Ajustments(ScrollBar *scroll, gdouble new_upper_limit, gdouble new_page_size, gdouble new_step_increment,gdouble new_page_increment ) {
    // Mettre à jour l'ajustement vertical si nécessaire
    if (scroll->h_adjustment) {
        gdouble lower_limit = gtk_adjustment_get_lower(scroll->h_adjustment);
        // Reconfigurer l'ajustement vertical avec la nouvelle limite supérieure et la taille de la page
        gtk_adjustment_configure(scroll->h_adjustment,
                                 scroll->h_value,          // Position actuelle
                                 lower_limit,              // Limite inférieure
                                 new_upper_limit,          // Nouvelle limite supérieure
                                 new_step_increment,           // Incrément du défilement
                                 new_page_increment,           // Incrément de la zone cliquable
                                 new_page_size);           // Nouvelle taille de la page
    }
}

void ChangerPolitiqueHorizontale(ScrollBar*scroll, GtkPolicyType policy) {
    scroll->h_policy = policy;
    if(scroll->scrolled_window) {
        gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll->scrolled_window),scroll->h_policy,scroll->v_policy);
    }
}

void ChangerPolitiqueVerticale(ScrollBar *scroll, GtkPolicyType policy) {
    scroll->v_policy = policy;
    if(scroll->scrolled_window) {
        gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll->scrolled_window),scroll->h_policy,scroll->v_policy);
    }
}

// Scroll to end
void ScrollToEnd(ScrollBar *scroll) {
    gdouble upper = gtk_adjustment_get_upper(scroll->h_adjustment);
    gdouble page_size = gtk_adjustment_get_page_size(scroll->h_adjustment);
    gtk_adjustment_set_value(scroll->h_adjustment, upper - page_size);
}

