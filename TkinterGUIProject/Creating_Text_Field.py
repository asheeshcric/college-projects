from tkinter import *

#text widget is not a theme widget of ttk module. So, we don't have to import the ttk module.

root = Tk()

text = Text(root, height = 10, width = 40)  #Height and width are defined in characters
text.pack()

text.config(wrap = 'word')  #Make each line on the box to wrap after a complete word
                            #By default it wraps by a character

#To get the desired content from the textbox:
print(text.get('1.0', 'end'))      #Here '1.0' represents 'line.char', i.e The 0th character of the first line
                            #'end' represents the end of the text in the box. So this gives all the text in the box

print(text.get('1.0', '1.end')) #Gives the first logical line of the textbox

#Here logical line refers to the line which ends with a new line character, i.e '\n'

#To insert text at any position in the text box:
text.insert('1.0 + 2 lines', 'Inserted text')   #Inserts the text in the 3rd line from the start

text.insert('1.0 + 2 lines lineend', 'Another inserted text')
#This inserts the text at the end of the third line

#To delete any text in the box:
text.delete('1.0','1.0 lineend + 1 chars')
#Doing this not only deletes the 1st line, but also deletes the remaining new line character
#in the first line


#To replace text in the box:
text.replace('1.0', '1.0  lineend', 'This is the replaced text')

#To configure the state:
text.config(state = 'disabled')
text.config(state = 'normal')

#About Tags:
#A tag is a set of characters to which we can perform several changes using the tagname:

text.tag_add('tag_name', '1.0', '1.0 wordend')  #Creates a tag from 1.0 to 1.0 wordend
text.tag_configure('tag_name', background = 'yellow')
text.tag_remove('tag_name', '1.1', '1.3')

#To get the range of characters included in a tag:
text.tag_ranges('tag_name')

#To get the names of tags used in the text box:
text.tag_names()
text.tag_names('1.0')   #Shows the tag name for the 1st character

text.replace('tag_name.first', 'tag_name.last', 'Replaced text')#Replaces the characters of the tag
text.tag_delete('tag_name')

#About Marks:
#A mark is the position where you want to insert something or where your mouse position is
#currently

text.mark_names()   #Shows the names of the marks which are insert and current

text.insert('insert', '_')
text.mark_set('my_mark', 'end')     #Sets the created mark 'my_mark' at the end of the text

text.mark_gravity('my_mark', 'right') #Decides whether to shift the inserted text to left/right

text.mark_unset('my_mark')  #Deletes the mark you created earlier

#To insert image or widget to the textbox:

#   new_image = PhotoImage(file = '\Location')
#    text.image_create('insert', image = new_image)

#Adding a button to the text field:
button = Button(text, text = 'Click Me')
text.window_create('insert', window = button)

