import os
import tkinter as tk

def playScum():
    os.system(command="gcc main.cpp")

# def openRules():


window = tk.Tk()

frame1 = tk.Frame(master=window, width=200, height=100)
frame1.pack(fill=tk.BOTH, side=tk.TOP, expand=True)
title = tk.Label(text="Welcome to Scum!", master=frame1)
title.pack()

frame2 = tk.Frame(master=window, width=100)
frame2.pack(fill=tk.BOTH, side=tk.TOP, expand=True)
playBtn = tk.Button(text="Play", master=frame2, command=playScum)
playBtn.pack()

frame3 = tk.Frame(master=window, width=100)
frame3.pack(fill=tk.BOTH, side=tk.TOP, expand=True)
# ruleBtn = tk.Button(text="Rules", master=frame3, command=openRules)
# ruleBtn.pack()

window.mainloop()