import os
import tkinter as tk
from tkinter import ttk
from tkinter import *


LARGEFONT =("System", 35)
  
class tkinterApp(tk.Tk):
     
    def __init__(self, *args, **kwargs):
         
        tk.Tk.__init__(self, *args, **kwargs)
         
        container = tk.Frame(self) 
        container.pack(side = "top", fill = "both", expand = True)
  
        container.grid_rowconfigure(0, weight = 1)
        container.grid_columnconfigure(0, weight = 1)
  
        self.frames = {} 
  
        for F in (StartPage, RulesPage):
  
            frame = F(container, self)
            self.frames[F] = frame
            frame.grid(row = 0, column = 0, sticky ="nsew")
  
        self.show_frame(StartPage)
  
    def show_frame(self, cont):
        frame = self.frames[cont]
        frame.tkraise()

    def playScum(self):
        os.system(command="g++ main.cpp -std=c++11")
        os.system("./a.out")
  
class StartPage(tk.Frame):

    def __init__(self, parent, controller):

        tk.Frame.__init__(self, parent)
         
        label = ttk.Label(self, text ="SCUM", font = LARGEFONT)
        label.grid(row = 0, column = 1, padx = 10, pady = 10)
  
        playBtn = ttk.Button(self, text ="Play",
        command = lambda : controller.playScum())
        playBtn.grid(row = 1, column = 0, padx = 10, pady = 10)
  
        rulesBtn = ttk.Button(self, text ="Rules",
        command = lambda : controller.show_frame(RulesPage))
        rulesBtn.grid(row = 1, column = 2, padx = 10, pady = 10)
  
class RulesPage(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        label = ttk.Label(self, text ="Rules", font = LARGEFONT)
        label.grid(row = 0, column = 1, padx = 10, pady = 10)

        text = tk.Text(self, wrap=WORD)
        text.grid(row = 1, column = 2, padx = 10, pady = 10)
        self.grid_columnconfigure(2, weight=1)
        self.grid_rowconfigure(1, weight=1)

        ruleHeader = '''Scum is a shedding card game, where the first player to shed all of their cards wins.\n\n'''
        bulletList = '''-At least 3 players needed\n\n-Person with 3 of spades starts with that cards\n\n-Singles play on top of singles, doubles on top of doubles, etc.\n\n-Playing a single of the same rank on top of the previous card will skip the player to the left\n\n-“House” can be called out of turn when a player has the remaining cards of a rank that is currently on top of the center cards\n\n-Playing a 2 will clear the center cards and allow the player to start fresh (you cannot end the game with a 2)'''
        text.insert(tk.END, ruleHeader, 'text_body')
        text.insert(tk.END, bulletList, 'bulleted_list')

        backBtn = ttk.Button(self, text ="Menu",
                            command = lambda : controller.show_frame(StartPage))
     
        backBtn.grid(row = 1, column = 1, padx = 10, pady = 10)

app = tkinterApp()
app.mainloop()