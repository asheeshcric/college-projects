from tkinter import *
from tkinter import ttk

root = Tk()

text = Text(root, width = 50, height = 10, wrap = 'word')
text.grid(row = 0, column = 0)

scroll = ttk.Scrollbar(root, orient = VERTICAL)
scroll.grid(row = 0, column = 1, sticky = 'ns')
scroll.config(command = text.yview)

text.config(yscrollcommand = scroll.set)

while 1:
    x = (text.get('1.0', 'end'))
    if x != NULL:
        break
