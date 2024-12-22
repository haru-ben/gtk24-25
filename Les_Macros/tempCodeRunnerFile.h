#include"C:\Users\hp\Documents\gtkprojet\Les_Sdds\Fenetre.h"

#define Aucune_Pos              GTK_WIN_POS_NONE
#define Pos_Centre              GTK_WIN_POS_CENTER
#define Pos_du_curseur          GTK_WIN_POS_MOUSE
#define Pos_Tjrs_centrer        GTK_WIN_POS_CENTER_ALWAYS
#define Pos_Centrer_parent      GTK_WIN_POS_CENTER_ON_PARENT

/*
    Fonction Pour Iniatliser Le Programe 
*/

void Program_Begin(int Arv,char *Arg[])
{
    gtk_init(&Arv,&Arg);
}

/* 
    Show All Widgets
*/

void Show_Programm(Fenetre *F_Ptr)
{
    gtk_widget_show_all(F_Ptr->Wind);
}



/***************size******************/

/*
    La Fonction Definir_Taille Pour donner une taille a la fentre
    Les Entres : 
                    Pointeur De Type Fenetre, cordonnee x , cordonne y 
    Les Sorties :
                    Rien
*/
void Definir_Taille(Fenetre *f, gint x, gint y) {
    f->Size.X = x;
    f->Size.Y = y;
    gtk_window_set_default_size(GTK_WINDOW(f->Wind), x, y);//donner a la fentre une taille de x et y
}

/*
    La Fonction Recuperer_Taille pour récupérer la taille actuelle de la fenêtre.
    Les Entrées : 
                    Pointeur de type Fenetre
    Les Sorties :
                    Largeur et hauteur via une variable Taille .
*/
Taille Recuperer_Taille(Fenetre *f) {
   Taille T;
    if(!f)
    {
    printf("la fentre n'exsite pas");
    exit(-1);
    }
    T.X = f->Size.X;
    T.Y = f->Size.Y;
    return T;
}

/********rezizable*******/
/*
    La Fonction Definir_Redimensionnable pour définir si une fenêtre peut être redimensionnée ou non.
    Les Entrées :
                    Pointeur de type Fenetre, valeur booléenne (TRUE ou FALSE).
    Les Sorties :
                    Rien.
*/
void Definir_Redimensionnable(Fenetre *f, gboolean resizable) {
     if(!f)
    {
    printf("la fentre n'exsite pas");
    exit(-1);
    }
    f->Resizable = resizable;
    gtk_window_set_resizable(GTK_WINDOW(f->Wind), resizable); // donner ala fenetre cette propriétés
}


/******pos*********/
/*
    La Fonction Definir_Position pour positionner la fenêtre aux coordonnées données.
    Les Entrées :
                    Pointeur de type Fenetre, coordonnées x et y.
    Les Sorties :
                    Rien.
*/
void Definir_Position(Fenetre *f, gint x, gint y) {
     if(!f)
      {
      printf("la fentre n'exsite pas");
      exit(-1);
      }
    f->Position.X = x;
    f->Position.Y = y;
    gtk_window_move(GTK_WINDOW(f->Wind), x, y);
}

/*
    La Fonction Recuperer_Position pour récupérer la position actuelle de la fenêtre.
    Les Entrées :
                    Pointeur de type Fenetre.
    Les Sorties :
                    Une structure Position contenant les coordonnées x et y.
*/
Position Recuperer_Position(Fenetre *f) {
     Position pos;
     if(!f)
       {
         printf("la fentre n'exsite pas");
         exit(-1);
       }
    gtk_window_get_position(GTK_WINDOW(f->Wind), &pos.X, &pos.Y);
    return pos;
}

/*
    La Fonction Definir_Position_Connu pour définir la position connue d'une fenêtre.
    Les Entrées :
                    Pointeur de type Fenetre, valeur entière correspondant à la position.
    Les Sorties :
                    Rien.
*/
void Definir_Position_Connu(Fenetre *f, gint position) {
    if(!f)
       {
        printf("la fentre n'exsite pas");
        exit(-1);
       }
    switch (position) {
        case 0:
            gtk_window_set_position(GTK_WINDOW(f->Wind), Aucune_Pos);
            break;
        case 1:
            gtk_window_set_position(GTK_WINDOW(f->Wind), Pos_Centre);
            break;
        case 2:
            gtk_window_set_position(GTK_WINDOW(f->Wind), Pos_du_curseur);
            break;
        case 3:
            gtk_window_set_position(GTK_WINDOW(f->Wind), Pos_Tjrs_centrer);
            break;
        case 4:
            gtk_window_set_position(GTK_WINDOW(f->Wind), Pos_Centrer_parent);
            break;
        default:
            // Gestion de l'erreur ou position par défaut si nécessaire
            break;
    }
}

/*
    La Fonction mettre_en_plein_ecran pour mettre la fenêtre en plein écran.
    Les Entrées :
                    Pointeur de type Fenetre.
    Les Sorties :
                    Rien.
*/
void mettre_en_plein_ecran(Fenetre *f) {
    if(!f)
      {
       printf("la fentre n'exsite pas");
       exit(-1);
      }
    gtk_window_fullscreen(GTK_WINDOW(f->Wind));
}

/*
    La Fonction quitter_plein_ecran pour quitter le mode plein écran.
    Les Entrées :
                    Pointeur de type Fenetre.
    Les Sorties :
                    Rien.
*/
void quitter_plein_ecran(Fenetre *f) {
    if(!f)
     {
      printf("la fentre n'exsite pas");
      exit(-1);
     }
    gtk_window_unfullscreen(GTK_WINDOW(f->Wind));
}

Fenetre* cree_fenetre()
{
    Fenetre* fen=(Fenetre*)malloc(sizeof(Fenetre));
    if(!fen)
    {
        printf("Erreur dans la fenetre");
        exit(-1);
    }
    if(!fen->Wind)
    {
        printf("Erreur dans la fenetre");
        exit(-1);
    }
    return (Fenetre*)fen;
}


void Afficher_Fenetre(Fenetre* fen)
{
    if(!fen)
    {
        printf("Erreur dans la fenetre");
        exit(-1);
    }
    if(!fen->Wind)
    {
        printf("Erruer dans la fenetre");
        exit(-1);
    }
    gtk_widget_show_all(fen->Wind);
}




void set_window_type(Fenetre* fen,gboolean type)
{
    if(!fen)
       exit(-1);
    if(!fen->Wind)
    {
        printf("Erruer dans la fenetre");
        exit(-1);
    }
    if(type)
        fen->Wind=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    else
        fen->Wind=gtk_window_new(GTK_WINDOW_POPUP);
    fen->Type=type;
}


void set_window_decorate(Fenetre *fen,gboolean Headbar)
{
    if(!fen)
    {
        printf("Erreur dans l'adresse fenetre");
        exit(-1);
    }
    if(!fen->Wind)
    {
        printf("Erruer dans la fenetre");
        exit(-1);
    }
    // Applique la d�coration en fonction du param�tre decorate
    gtk_window_set_decorated(GTK_WINDOW(fen->Wind), Headbar);
    fen->Headbar = Headbar;
}
                                        
/*
    La Fonction Fenetre_Set_BackGround_Image Pour Ajoute Un Image Comme BackGround D'une Window
    Les Entres : 
                    Pointeur De Type Fenetre, Chaine De Caracteres 
    Les Sorties :
                    Rien
*/
void Fenetre_Set_BackGround_Image(Fenetre *F_Ptr,gchar *BackGroundPath)                
{
    /*
        Test D'Exsitance
    */
    if (!F_Ptr)
    {
        printf("Erreur Dans L'Adress Fenetre. ");
        exit(0);
    }

    /*
        Test D'Exsitance
    */
    if(!F_Ptr->Wind)
    {
        printf("Erruer Dans L'Adress Wind.");
        exit(0);
    }

    /*
        Création D'un Conteneur GtkOverlay Joue Le Role Comme Box Ou Fixed Pour Encapsule L'image
    */
    GtkWidget *overlay = gtk_overlay_new();
    /*
        Affecter Notre Overlay Cree A Notre Fenetre Pass En Parametres 
    */
    gtk_container_add(GTK_CONTAINER(F_Ptr->Wind), overlay);

    F_Ptr->BackGround = BackGroundPath;

    /* 
        Chargement L'image A Traiter
    */
    GtkWidget *Image = gtk_image_new_from_file(F_Ptr->BackGround);

    F_Ptr->BackGround = BackGroundPath;
    /*
        Ajout de l'image au conteneur GtkOverlay
    */
    gtk_overlay_add_overlay(GTK_OVERLAY(overlay),Image);

}
/**********************scrollbar********************************/
typedef struct {
    GtkWidget *scrolled_window;  // Le widget de défilement
    gboolean scroll_horizontal;  // Activation du défilement horizontal
    gboolean scroll_vertical;    // Activation du défilement vertical
    GtkPolicyType h_policy;      // Politique de défilement horizontal
    GtkPolicyType v_policy;      // Politique de défilement vertical
    gdouble h_value;            // Valeur de défilement horizontal
    gdouble v_value;            // Valeur de défilement vertical
    gdouble h_step;             // Pas de défilement horizontal
    gdouble v_step;             // Pas de défilement vertical
    GtkAdjustment *h_adjustment; // Ajustement horizontal
    GtkAdjustment *v_adjustment; // Ajustement vertical
} ScrollBar;

/*valeur de policy:
Les différentes politiques disponibles
GTK_POLICY_ALWAYS    // La barre de défilement est toujours visible
GTK_POLICY_NEVER     // La barre de défilement n'est jamais visible
GTK_POLICY_AUTOMATIC // La barre de défilement apparaît seulement si nécessaire
*/
// Fonction d'initialisation du scrollbar
void InitScrollBar(ScrollBar *scroll) {
    scroll->scroll_horizontal = TRUE;
    scroll->scroll_vertical = TRUE;
    scroll->h_policy = GTK_POLICY_ALWAYS;
    scroll->v_policy = GTK_POLICY_ALWAYS;
    scroll->h_value = 0.0;
    scroll->v_value = 0.0;
    scroll->h_step = 10.0;
    scroll->v_step = 10.0;
    scroll->scrolled_window = NULL;
    scroll->h_adjustment = NULL;
    scroll->v_adjustment = NULL;
}
// Création du scrolled window
void CreerScrollBar(Fenetre *F, ScrollBar*scroll) {
    // Création du widget scrolled window
    scroll->scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    
    // Configuration des politiques de défilement
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll->scrolled_window),scroll->h_policy,scroll->v_policy);
    
    // Récupération des ajustements
    scroll->h_adjustment = gtk_scrolled_window_get_hadjustment(GTK_SCROLLED_WINDOW(scroll->scrolled_window));
    scroll->v_adjustment = gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW(scroll->scrolled_window));
    
    
    // 4. Exemple pratique avec un grand texte
    GtkWidget *text_view = gtk_text_view_new();
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    
    // Ajout de beaucoup de texte pour forcer le défilement
    gtk_text_buffer_set_text(buffer,
        "Ligne 1\nLigne 2\nLigne 3\n..."  // Beaucoup de texte
        "Dernière ligne\n",
        -1);
    // Ajout du scrolled window à la fenêtre
      gtk_container_add(GTK_CONTAINER(scroll->scrolled_window), text_view);

    gtk_container_add(GTK_CONTAINER(F->Wind), scroll->scrolled_window);
}

// Changer la politique de défilement horizontal
void ChangerPolitiqueHorizontale(ScrollBar*scroll, GtkPolicyType policy) {
    scroll->h_policy = policy;
    if(scroll->scrolled_window) {
        gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll->scrolled_window),scroll->h_policy,scroll->v_policy);
    }
}

// Changer la politique de défilement vertical
void ChangerPolitiqueVerticale(ScrollBar *scroll, GtkPolicyType policy) {
    scroll->v_policy = policy;
    if(scroll->scrolled_window) {
        gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll->scrolled_window),scroll->h_policy,scroll->v_policy);
    }
}

// Définir la position du défilement horizontal
void SetPositionHorizontale(ScrollBar*scroll, gdouble value) {
    if(scroll->h_adjustment) {
        gdouble max = gtk_adjustment_get_upper(scroll->h_adjustment) -
                     gtk_adjustment_get_page_size(scroll->h_adjustment);
                     printf("%f",max);
        scroll->h_value = CLAMP(value, 0.0, max);
        gtk_adjustment_set_value(scroll->h_adjustment, scroll->h_value);
    }
}
