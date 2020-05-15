import pygame
import time
import random


pygame.init()
display_width = 1100
display_height = 948
clock = pygame.time.Clock()
text_color = (255, 100, 0)
text_score = (242, 255, 179)
gameDisplay = pygame.display.set_mode((display_width, display_height))
background = pygame.image.load("tlo.jpg")
Image = pygame.image.load("postac3.png")
object = pygame.image.load("komórka2.png")
wall1 = pygame.image.load("sciana1.jpg")
wall2 = pygame.image.load("sciana2.jpg")
wall3 = pygame.image.load("sciana4.jpg")
wall4 = pygame.image.load("sciana5.jpg")
backg_menu = pygame.image.load("tlo_menu.jpg")
backg_button = pygame.image.load("button.png")
score = 0
x = [display_width * 0.5, random.randrange(0, display_width - 55)]
y = [display_height * 0.8, random.randrange(0, display_height - 55)]
move_x = 0
move_y = 0
difficulty = "Łatwy"

def player(x, y):
    gameDisplay.blit(Image, (x, y))


def fun_object(objx, objy):
    gameDisplay.blit(object, (objx , objy))


def wall(x, y, difficulty):
    gameDisplay.blit(wall1, (x[0], y[0]))
    gameDisplay.blit(wall2, (x[1], y[1]))
    gameDisplay.blit(wall2, (x[2], y[2]))
    gameDisplay.blit(wall3, (x[3], y[3]))
    gameDisplay.blit(wall4, (x[4], y[4]))
    gameDisplay.blit(wall4, (x[5], y[5]))
    if difficulty == "Średni" or difficulty == "Trudny":
        gameDisplay.blit(wall2, (x[6], y[6]))
        gameDisplay.blit(wall4, (x[7], y[7]))
    if difficulty == "Trudny":
        gameDisplay.blit(wall4, (x[8], y[8]))
        gameDisplay.blit(wall4, (x[9], y[9]))
        gameDisplay.blit(wall3, (x[10], y[10]))


def message(text, font):
    textSurface = font.render(text, True, text_color)
    return textSurface, textSurface.get_rect()


def message_show(text):
    global x, y, score
    Text = pygame.font.Font('Gotu-Regular.ttf',115)
    TextSurf, TextRect = message(text, Text)
    TextRect.center = ((display_width/2),(display_height/2 - 120))
    gameDisplay.blit(TextSurf, TextRect)

    pygame.display.update()
    time.sleep(2)
    x = [display_width * 0.5, random.randrange(0, display_width - 55)]
    y = [display_height * 0.8, random.randrange(0, display_height - 55)]
    score = 0
    game()


def crash():
    message_show('Koniec')


def score_text(surf, text, size, x, y):
    font = pygame.font.Font('Gotu-Regular.ttf', 60)
    text_surf = font.render(text, True, text_score)
    text_rect = text_surf.get_rect()
    text_rect.midtop = (x, y) # srodek-gora kwadratu
    gameDisplay.blit(text_surf, text_rect)


font = pygame.font.Font('Gotu-Regular.ttf', 40)


def draw_text(text , font, color, surface , x, y):
    text_obj = font.render(text, True, (177, 1, 88))
    text_rect = text_obj.get_rect()
    text_rect.topleft = (x, y)
    gameDisplay.blit(text_obj, text_rect)


click2 = False
click = False
'#https://www.youtube.com/watch?v=0RryiSjpJn0'
def menu():
    click2 = False
    while True:

        gameDisplay.blit(backg_menu, (0, -300))

        mx, my = pygame.mouse.get_pos()

        button_1 = pygame.Rect(display_width/2 - 125, 300, 250, 50)
        button_2 = pygame.Rect(display_width/2 - 125, 400, 250, 50)
        button_3 = pygame.Rect(display_width/2 - 125, 500, 250, 50)

        pygame.draw.ellipse(gameDisplay, (0, 0, 0), button_1)
        pygame.draw.ellipse(gameDisplay, (0, 0, 0), button_2)
        pygame.draw.ellipse(gameDisplay, (0, 0, 0), button_3)

        gameDisplay.blit(backg_button, (display_width/2 - 125,300))
        draw_text("Start", font, (255, 0, 0), gameDisplay, display_width/2 - 45, 292)
        gameDisplay.blit(backg_button, (display_width/2 - 125, 400))
        draw_text("Muzyka", font, (255, 0, 0), gameDisplay, display_width/2 - 65, 392)
        gameDisplay.blit(backg_button, (display_width / 2 - 125, 500))
        draw_text("Poziom", font, (255, 0, 0), gameDisplay, display_width / 2 - 65, 492)

        if button_1.collidepoint((mx, my)):
            if click:
                game()

        if button_2.collidepoint((mx, my)):
            if click:
                music()

        click = False
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    pygame.quit()
                    quit()
            if event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 1:
                    click = True
        #poziomy
        if button_3.collidepoint((mx, my)):
            click2 = True
        if click2 == True:
            button_4 = pygame.Rect(140, 600, 250, 50)
            button_5 = pygame.Rect(430, 600, 250, 50)
            button_6 = pygame.Rect(720, 600, 250, 50)
            pygame.draw.ellipse(gameDisplay, (0, 0, 0), button_4)
            pygame.draw.ellipse(gameDisplay, (0, 0, 0), button_5)
            pygame.draw.ellipse(gameDisplay, (0, 0, 0), button_6)
            gameDisplay.blit(backg_button, (140, 600))
            gameDisplay.blit(backg_button, (430, 600))
            gameDisplay.blit(backg_button, (720, 600))
            draw_text("Łatwy", font, (255, 0, 0), gameDisplay, 210, 590)
            draw_text("Średni", font, (255, 0, 0), gameDisplay, 500, 595)
            draw_text("Trudny", font, (255, 0, 0), gameDisplay, 790, 590)
            global difficulty
            if button_4.collidepoint((mx, my)):
                if click:
                    difficulty = "Łatwy"
                    game()
                    click2 = False
            if button_5.collidepoint((mx, my)):
                if click:
                    difficulty = "Średni"
                    game()
                    click2 = False
            if button_6.collidepoint((mx, my)):
                if click:
                    difficulty = "Trudny"
                    game()
                    click2 = False

        pygame.display.update()

click3 = False

def music():
    running = True
    while running:
        gameDisplay.fill((0, 0, 0))
        gameDisplay.blit(backg_menu, (0, -300))

        #on = pygame.mixer.music.load("on&on.mp3")

        mx, my = pygame.mouse.get_pos()

        button_1 = pygame.Rect(200, 300, 250, 50)
        button_2 = pygame.Rect(200, 400, 250, 50)
        button_3 = pygame.Rect(200, 500, 250, 50)

        pygame.draw.ellipse(gameDisplay, (0, 0, 0), button_1)
        pygame.draw.ellipse(gameDisplay, (0, 0, 0), button_2)
        pygame.draw.ellipse(gameDisplay, (0, 0, 0), button_3)

        gameDisplay.blit(backg_button, (200, 300))
        draw_text("Witcher3", font, (255, 0, 0), gameDisplay, 235, 292)
        gameDisplay.blit(backg_button, (200, 400))
        draw_text("On&on", font, (255, 0, 0), gameDisplay, 245, 392)
        gameDisplay.blit(backg_button, (200, 500))
        draw_text("Can't stop", font, (255, 0, 0), gameDisplay, 225, 492)

        if button_1.collidepoint((mx, my)):
            if click3 == True:
                pygame.mixer.music.load("muzyka1_wiesiek (online-audio-converter.com).wav")
                pygame.mixer.music.play(1, 0)

        if button_2.collidepoint((mx, my)):
            if click3 == True:
                pygame.mixer.music.load("on&on (online-audio-converter.com).wav")
                pygame.mixer.music.play(1, 0)

        if button_3.collidepoint((mx, my)):
            if click3 == True:
                pygame.mixer.music.load("Ican'tstop (online-audio-converter.com).wav")
                pygame.mixer.music.play(1, 0)


        click3 = False
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
            if event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 1:
                    click3 = True
        pygame.display.update()


def collision(wall_x, wall_y, x1, x2, y1, y2, player_x, player_y, selection):
    if player_y < wall_y + y1 and player_y > wall_y + y2:
        if player_x > wall_x + x1 and player_x < wall_x + x2:
            selection()


def collisionObject():
    global x, y, score
    x[1] = random.randrange(0, display_width - 55)
    y[1] = random.randrange(0, display_height - 55)
    score += 1


def objectParameters():
    global x, y
    x[1] = random.randrange(0, display_width - 55)
    y[1] = random.randrange(0, display_height - 55)


def game():
    global x, y, move_x, move_y,score
    wall_x1 = [150, 700, 200, 400, 900, 800, 300, 600, 350, 400, 800]
    wall_y1 = [200, 250, 800, 100, 700, 450, 400, 600, 600, 200, 100]
    gameExit = False
    while not gameExit:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            speed = 5
            if difficulty == "Średni":
                speed = 10
            elif difficulty == "Trudny":
                speed = 15
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    move_x = -speed
                elif event.key == pygame.K_RIGHT:
                    move_x = speed
                elif event.key == pygame.K_UP:
                    move_y = -speed
                elif event.key == pygame.K_DOWN:
                    move_y = speed
                elif event.key == pygame.K_ESCAPE:
                    gameExit = True
                    score = 0

            if event.type == pygame.KEYUP:
                if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                    move_x = 0
                elif event.key == pygame.K_UP or event.key == pygame.K_DOWN:
                    move_y = 0

        x[0] += move_x
        y[0] += move_y
        gameDisplay.blit(background, (0, 0))
        player(x[0], y[0])
        fun_object(x[1], y[1])
        wall(wall_x1, wall_y1, difficulty)
        score_text(gameDisplay, str(score), 4, 555, 10)

        # kolizja z krawędziami
        if x[0] < 0:
            x[0] += display_width
        elif x[0] > display_width:
            x[0] -= display_width
        elif y[0] < 0:
            y[0] += display_height
        elif y[0] > display_height:
            y[0] -= display_height

        #kolizja sciany
        collision(wall_x1[0], wall_y1[0], -50, 40, 400, -49, x[0], y[0], crash)
        collision(wall_x1[1], wall_y1[1], -50, 300, 40, -50, x[0], y[0], crash)
        collision(wall_x1[2], wall_y1[2], -50, 300, 40, -49, x[0], y[0], crash)
        collision(wall_x1[3], wall_y1[3], -50, 100, 40, -49, x[0], y[0], crash)
        collision(wall_x1[4], wall_y1[4], -50, 40, 100, -49, x[0], y[0], crash)
        collision(wall_x1[5], wall_y1[5], -50, 40, 100, -49, x[0], y[0], crash)
        # kolizja obiekt - sciana
        collision(wall_x1[0], wall_y1[0], -50, 40, 400, -49, x[1], y[1], objectParameters)
        collision(wall_x1[1], wall_y1[1], -50, 300, 40, -50, x[1], y[1], objectParameters)
        collision(wall_x1[2], wall_y1[2], -50, 300, 40, -49, x[1], y[1], objectParameters)
        collision(wall_x1[3], wall_y1[3], -50, 100, 40, -49, x[1], y[1], objectParameters)
        collision(wall_x1[4], wall_y1[4], -50, 40, 100, -49, x[1], y[1], objectParameters)
        collision(wall_x1[5], wall_y1[5], -50, 40, 100, -49, x[1], y[1], objectParameters)

        if difficulty == "Średni" or difficulty == "Trudny":
            collision(wall_x1[6], wall_y1[6], -50, 300, 40, -50, x[0], y[0], crash)
            collision(wall_x1[7], wall_y1[7], -50, 40, 100, -49, x[0], y[0], crash)
            collision(wall_x1[6], wall_y1[6], -50, 300, 40, -50, x[1], y[1], objectParameters)
            collision(wall_x1[7], wall_y1[7], -50, 40, 100, -49, x[1], y[1], objectParameters)
        if difficulty == "Trudny":
            collision(wall_x1[8], wall_y1[8], -50, 40, 100, -49, x[0], y[0], crash)
            collision(wall_x1[9], wall_y1[9], -50, 40, 100, -49, x[0], y[0], crash)
            collision(wall_x1[10], wall_y1[10], -50, 100, 40, -49, x[0], y[0], crash)
            collision(wall_x1[8], wall_y1[8], -50, 40, 100, -49, x[1], y[1], objectParameters)
            collision(wall_x1[9], wall_y1[9], -50, 40, 100, -49, x[1], y[1], objectParameters)
            collision(wall_x1[10], wall_y1[10], -50, 100, 40, -49, x[1], y[1], objectParameters)
        #kolizja gracz - obiekt
        collision(x[1], y[1], -50, 50, 50, -50, x[0], y[0],  collisionObject)

        pygame.display.update()
        clock.tick(120)


menu()
pygame.quit()
quit()