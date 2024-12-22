#include"C:\Users\hp\Documents\gtkprojet\Les_Macros\Fenetre.h"
typedef struct {
    GtkWidget *scrolled_window;  // Le widget de défilement
    GtkWidget *parent;           // Le widget parent (conteneur)
    GtkWidget *fils;             // Le widget enfant à faire défiler
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