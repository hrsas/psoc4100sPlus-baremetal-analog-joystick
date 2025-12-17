import pygame
import random
import sys
import serial

ser = serial.Serial('COM4', 115200, timeout=0)
direction = 'C'

pygame.init()

WIDTH, HEIGHT = 400, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Retro Endless Runner")
clock = pygame.time.Clock()


car_img = pygame.image.load("assets/car1.png").convert_alpha()
car_img = pygame.transform.scale(car_img, (32, 64))

obstacle_imgs = [
    pygame.image.load("assets/OB1.png").convert_alpha(),
    pygame.image.load("assets/OB2.png").convert_alpha(),
    pygame.image.load("assets/OB3.png").convert_alpha()
]

obstacle_imgs = [pygame.transform.scale(img, (32, 64)) for img in obstacle_imgs]

road_img = pygame.image.load("assets/road.png").convert()
road_img = pygame.transform.scale(road_img, (WIDTH, HEIGHT))
road_y = 0
score = 0
score_timer = 0

ROAD_WIDTH = 200
ROAD_LEFT = (WIDTH - ROAD_WIDTH) // 2

LANES = [
    ROAD_LEFT + ROAD_WIDTH * 0.25,
    ROAD_LEFT + ROAD_WIDTH * 0.75
]

lane_index = 0

player_width = 40
player_height = 60
player_y = HEIGHT - player_height - 20
player_x = LANES[lane_index] - player_width // 2

obstacles = []   # list of (rect, image)
obstacle_width = 40
obstacle_height = 60
obstacle_speed = 5
spawn_timer = 0

score_font = pygame.font.Font("assets/font.ttf", 20)

running = True
while running:
    clock.tick(60)
    score_timer += 1
    if score_timer >= 6:   # ~10 score units per second at 60 FPS
        score += 1
        score_timer = 0
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # ----- UART INPUT -----
    while ser.in_waiting:
        cmd = ser.read().decode(errors='ignore')
        if cmd in ('L', 'R', 'C'):
            direction = cmd

    if direction == 'L':
        lane_index = 0
    elif direction == 'R':
        lane_index = 1

    player_x = LANES[lane_index] - player_width // 2

    obstacle_speed = 5 + score // 500

    spawn_timer += 1
    if spawn_timer > 60:
        spawn_timer = 0
        lane_x = random.choice(LANES)
        img = random.choice(obstacle_imgs)

        rect = pygame.Rect(
            lane_x - obstacle_width // 2,
            -obstacle_height,
            obstacle_width,
            obstacle_height
        )

        obstacles.append((rect, img))

    for rect, _ in obstacles:
        rect.y += obstacle_speed

    obstacles = [(r, i) for (r, i) in obstacles if r.y < HEIGHT]

    player_rect = pygame.Rect(player_x, player_y,
                              player_width, player_height)

    for rect, _ in obstacles:
        if player_rect.colliderect(rect):
            print("GAME OVER")
            running = False

    road_y += obstacle_speed
    if road_y >= HEIGHT:
        road_y = 0

    screen.blit(road_img, (0, road_y))
    screen.blit(road_img, (0, road_y - HEIGHT))

    for rect, img in obstacles:
        screen.blit(img, (rect.x, rect.y))

    screen.blit(car_img, (player_x, player_y))

    # ----- SCORE HUD -----
    score_str = f"SCORE {score:05d}"

    shadow = score_font.render(score_str, True, (20, 20, 20))
    screen.blit(shadow, (14, 12))

    score_text = score_font.render(score_str, True, (255, 230, 80))
    screen.blit(score_text, (12, 10))

    
    pygame.display.flip()

pygame.quit()
sys.exit()
