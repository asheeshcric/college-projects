from tkinter import *
from tkinter import ttk

class HelloApp:
    def __init__(self, root):
        self.root = root
        self.label = ttk.Label(self.root, text = 'Hello Guys')
        self.label.grid(row = 0, column = 0, columnspan = 2)

        self.button1 = ttk.Button(self.root, text = 'Texas', command = self.hello1)
        self.button1.grid(row = 1, column = 0)

        self.button2 = ttk.Button(root, text = 'Hawaii', command = self.hello2)
        self.button2.grid(row = 1, column = 1)

    def hello1(self):
        self.label.config(text = 'Hello Texas')

    def hello2(self):
        self.label.config(text = 'Hello Hawaii')


def main():
    root = Tk()
    app_object = HelloApp(root)
    root.mainloop()             #Continues the program again and again and waits for any event
                                #that occurs


if __name__ == "__main__": main()
