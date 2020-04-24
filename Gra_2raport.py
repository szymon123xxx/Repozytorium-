import pygame
import time
import random

pygame.init()
display_width = 1100
display_height = 948
clock = pygame.time.Clock()
text_color = (255,100,0)

gameDisplay = pygame.display.set_mode( ( display_width , display_height ) )
background = pygame.image.load("tlo.jpg")
Image = pygame.image.load("postac3.png")
object = pygame.image.load("komórka2.png")
wall1 = pygame.image.load("sciana1.jpg")
wall2 = pygame.image.load("sciana2.jpg")
wall3 = pygame.image.load("sciana4.jpg")
wall4 = pygame.image.load("sciana5.jpg")

def player(x,y):
    gameDisplay.blit(Image, (x, y))

def fun_object(objx, objy):
    gameDisplay.blit(object, (objx , objy))

def wall(x,y):
    gameDisplay.blit(wall1, (x - 50, y))
    gameDisplay.blit(wall2, (x + 500 , y + 50))
    gameDisplay.blit(wall2, (x , y + 600))
    gameDisplay.blit(wall3, (x + 200, y - 100))
    gameDisplay.blit(wall4, (x + 700, y + 500))
    gameDisplay.blit(wall4, (x + 600, y + 250))

def message(text, font):
    textSurface = font.render(text, True, text_color)
    return textSurface, textSurface.get_rect()

def message_show(text):
    Text = pygame.font.Font('Gotu-Regular.ttf',115)
    TextSurf , TextRect = message(text, Text)
    TextRect.center = ((display_width/2),(display_height/2 - 120))
    gameDisplay.blit(TextSurf, TextRect)

    pygame.display.update()
    time.sleep(2)
    game()

def crash():
    message_show('Koniec')

def game():
    wall_x1 = 200
    wall_y1 = 200
    objx = random.randrange(0, display_width - 55)
    objy = random.randrange(0, display_height - 55)
    x = display_width * 0.5
    y = display_height * 0.8

    move_x = 0
    move_y = 0
    gameExit = False
    while not gameExit:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    move_x = -5
                elif event.key == pygame.K_RIGHT:
                    move_x = 5
                elif event.key == pygame.K_UP:
                    move_y = -5
                elif event.key == pygame.K_DOWN:
                    move_y = 5

            if event.type == pygame.KEYUP:
                if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                    move_x = 0
                elif event.key == pygame.K_UP or event.key == pygame.K_DOWN:
                    move_y = 0

        x += move_x
        y += move_y
        gameDisplay.blit(background,(0,0))
        player(x,y)
        fun_object(objx,objy)
        wall(wall_x1, wall_y1)

        # wychodzenie poza krawędzie
        if x < 0:
            x += display_width
        elif x > display_width:
            x -= display_width
        elif y < 0:
            y += display_height
        elif y > display_height:
            y -= display_height
    #---------------------------------------------------------#
        # zderzenie pierwsza ściana
        if y < wall_y1 + 400 and y > wall_y1 - 49:
            if x > wall_x1 - 100 and x < wall_x1 - 10:
                crash()
        # zderzenie druga ściana
        if y < wall_y1 + 90 and y > wall_y1 :
            if x > wall_x1 + 450 and x < wall_x1 + 800:
                crash()
        # zderzenie trzecia ściana
        if y < wall_y1 + 640 and y > wall_y1 + 560:
            if x > wall_x1 - 50 and x < wall_x1 + 300:
                crash()
        # zderzenie czwarta ściana
        if y < wall_y1 - 60 and y > wall_y1 - 140:
            if x > wall_x1 + 150 and x < wall_x1 + 300:
                crash()
        # zderzenie piąta ściana
        if y < wall_y1 + 600 and y > wall_y1 + 450:
            if x > wall_x1 + 650 and x < wall_x1 + 740:
                crash()
        # zderzenie szósta ściana
        if y < wall_y1 + 350 and y > wall_y1 + 200 :
            if x > wall_x1 + 550 and x < wall_x1 + 640:
                crash()
    # ---------------------------------------------------------#
        #zderzenie objektu z graczem
        if y < objy + 50 and y > objy - 50:
            if x > objx - 50 and x < objx + 50 :
                objx = random.randrange(0, display_width - 55)
                objy = random.randrange(0, display_height - 55)
    # ---------------------------------------------------------#
        # zderzenie pierwsza ściana - obiekt
        if objy < wall_y1 + 400 and objy > wall_y1 - 49:
            if objx > wall_x1 - 100 and objx < wall_x1 - 10:
                objx = random.randrange(0, display_width - 55)
                objy = random.randrange(0, display_height - 55)
        # zderzenie druga ściana - obiekt
        if objy < wall_y1 + 90 and objy > wall_y1:
            if objx > wall_x1 + 450 and objx < wall_x1 + 800:
                objx = random.randrange(0, display_width - 55)
                objy = random.randrange(0, display_height - 55)
        # zderzenie trzecia ściana - obiekt
        if objy < wall_y1 + 640 and objy > wall_y1 + 560:
            if objx > wall_x1 - 50 and objx < wall_x1 + 300:
                objx = random.randrange(0, display_width - 55)
                objy = random.randrange(0, display_height - 55)
        # zderzenie czwarta ściana - obiekt
        if objy < wall_y1 - 60 and objy > wall_y1 - 140:
            if objx > wall_x1 + 150 and objx < wall_x1 + 300:
                objx = random.randrange(0, display_width - 55)
                objy = random.randrange(0, display_height - 55)
        # zderzenie piąta ściana
        if objy < wall_y1 + 600 and objy > wall_y1 + 450:
            if objx > wall_x1 + 650 and objx < wall_x1 + 740:
                objx = random.randrange(0, display_width - 55)
                objy = random.randrange(0, display_height - 55)
        # zderzenie szósta ściana - obiekt
        if objy < wall_y1 + 350 and objy > wall_y1 + 200:
            if objx > wall_x1 + 550 and objx < wall_x1 + 640:
                objx = random.randrange(0, display_width - 55)
                objy = random.randrange(0, display_height - 55)


        pygame.display.update()
        clock.tick(60)


game()
pygame.quit()
quit()