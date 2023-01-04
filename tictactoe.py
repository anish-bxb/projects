from tkinter import *
from tkinter import messagebox

root = Tk()
root.title("Tic Tac Toe")
#root.geometry('1200x800')


clicked = True
count = 0

def disable_buttons():
    b1['state'] = 'disabled'
    b2['state'] = 'disabled'
    b3['state'] = 'disabled'
    b4['state'] = 'disabled'
    b5['state'] = 'disabled'
    b6['state'] = 'disabled'
    b7['state'] = 'disabled'
    b8['state'] = 'disabled'
    b9['state'] = 'disabled'
    if messagebox.askyesno("Tic Tac Toe", "Do you want to try again?"):
        reset()
    else:
        root.destroy()

def checkwin():
    
    if b1['text'] != ' ' and b1['text'] == b2['text'] == b3['text']:
        b1.config(bg = 'red')
        b2.config(bg = 'red')
        b3.config(bg = 'red')
        messagebox.showinfo("Tic Tac Toe", "Player {} has won".format(b1['text']))
        disable_buttons()
        
    elif b1['text'] != ' ' and b1['text'] == b4['text'] == b7['text']:

        b1.config(bg = 'red')
        b4.config(bg = 'red')
        b7.config(bg = 'red')
        messagebox.showinfo("Tic Tac Toe", "Player {} has won".format(b1['text']))
        disable_buttons()

    elif b1['text'] != ' ' and b1['text'] == b5['text'] == b9['text']:

        b1.config(bg = 'red')
        b5.config(bg = 'red')
        b9.config(bg = 'red')
        messagebox.showinfo("Tic Tac Toe", "Player {} has won".format(b1['text']))
        disable_buttons()

    elif b7['text'] != ' ' and b7['text'] == b8['text'] == b9['text']:

        b8.config(bg = 'red')
        b9.config(bg = 'red')
        b7.config(bg = 'red')
        messagebox.showinfo("Tic Tac Toe", "Player {} has won".format(b7['text']))
        disable_buttons()

    elif b7['text'] != ' ' and b7['text'] == b5['text'] == b3['text']:

        b3.config(bg = 'red')
        b5.config(bg = 'red')
        b7.config(bg = 'red')
        messagebox.showinfo("Tic Tac Toe", "Player {} has won".format(b7['text']))
        disable_buttons()

    elif b9['text'] != ' ' and b9['text'] == b6['text'] == b3['text']:

        b9.config(bg = 'red')
        b6.config(bg = 'red')
        b3.config(bg = 'red')
        messagebox.showinfo("Tic Tac Toe", "Player {} has won".format(b9['text']))
        disable_buttons()
        
    elif b2['text'] != ' ' and b2['text']== b5['text'] == b8['text']:

        b2.config(bg = 'red')
        b5.config(bg = 'red')
        b8.config(bg = 'red')
        messagebox.showinfo("Tic Tac Toe", "Player {} has won".format(b2['text']))
        disable_buttons()
        
    elif b4['text'] != ' ' and b4['text'] == b5['text'] == b6['text']:

        b5.config(bg = 'red')
        b4.config(bg = 'red')
        b6.config(bg = 'red')
        messagebox.showinfo("Tic Tac Toe", "Player {} has won".format(b4['text']))
        disable_buttons()
        
    elif count >= 9:
        messagebox.showinfo("Tic Tac Toe", "Draw!")
        disable_buttons()

    
def b_click(b):
    global clicked, count
    if (b['text'] == ' ' and clicked == True):
        b['text'] = 'X'
        count += 1
        clicked = False
        checkwin()

    elif (b['text'] ==' ' and clicked == False):
        b['text'] = 'O'
        count += 1
        clicked = True
        checkwin()

    else:
        messagebox.showerror("Tic Tac Toe", "Box already taken!\nPick another box")
        
def reset():
    global b1, b2, b3, b4, b5, b6, b7, b8, b9, clicked, count
    clicked = True
    count = 0
    b1 = Button(root, text = ' ', font = ('Comic sans', 20), height = 3, width = 6, bg = "SystemButtonFace", command = lambda: b_click(b1))
    b2 = Button(root, text = ' ', font = ('Comic sans', 20), height = 3, width = 6, bg = "SystemButtonFace", command = lambda: b_click(b2))
    b3 = Button(root, text = ' ', font = ('Comic sans', 20), height = 3, width = 6, bg = "SystemButtonFace", command = lambda: b_click(b3))

    b4 = Button(root, text = ' ', font = ('Comic sans', 20), height = 3, width = 6, bg = "SystemButtonFace", command = lambda: b_click(b4))
    b5 = Button(root, text = ' ', font = ('Comic sans', 20), height = 3, width = 6, bg = "SystemButtonFace", command = lambda: b_click(b5))
    b6 = Button(root, text = ' ', font = ('Comic sans', 20), height = 3, width = 6, bg = "SystemButtonFace", command = lambda: b_click(b6))

    b7 = Button(root, text = ' ', font = ('Comic sans', 20), height = 3, width = 6, bg = "SystemButtonFace", command = lambda: b_click(b7))
    b8 = Button(root, text = ' ', font = ('Comic sans', 20), height = 3, width = 6, bg = "SystemButtonFace", command = lambda: b_click(b8))
    b9 = Button(root, text = ' ', font = ('Comic sans', 20), height = 3, width = 6, bg = "SystemButtonFace", command = lambda: b_click(b9))

    b1.grid(row=0,column=1)
    b2.grid(row=0,column=2)
    b3.grid(row=0,column=3)

    b4.grid(row=1,column=1)
    b5.grid(row=1,column=2)
    b6.grid(row=1,column=3)

    b7.grid(row=2,column=1)
    b8.grid(row=2,column=2)
    b9.grid(row=2,column=3)

reset()

root.mainloop()
