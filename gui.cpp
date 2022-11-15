/*  This program contains the code for the Scum GUI
    Written by Lucas Pasquarelli
    CS498 Capstone
    Fall 2022 Semester
*/

#include<iostream>
#include<GameKit/gtk.h>

static void destroy(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

using namespace std;

int main(int argc, char *argv[])
{   
    gtk_init(&argc, &argv);
}