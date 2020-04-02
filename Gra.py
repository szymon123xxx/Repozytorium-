import pygame

pygame.init()
display_width = 1100
display_height = 948
clock = pygame.time.Clock()

gameDisplay = pygame.display.set_mode( ( display_width , display_height ) )
background = pygame.image.load("tlo.jpg")
Image = pygame.image.load("postac3.png")
def player(x,y):
    gameDisplay.blit(Image, (x, y))

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

    if x < 0:
        x += display_width
    elif x > display_width:
        x -= display_width
    elif y < 0:
        y += display_height
    elif y > display_height:
        y -= display_height

    pygame.display.update()
    clock.tick(60)

pygame.quit()
quit()