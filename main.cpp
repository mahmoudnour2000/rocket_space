#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"SFML\Audio.hpp"
#include<vector>
#include<windows.h>
using namespace sf;
void main1();
void instructions();
void gameover();
void win();
int main2 = 0;

  int main(){

    if(main2== 0){
    main1();}
    RenderWindow window(VideoMode(800, 600), "Space Mission Game");
    window.setFramerateLimit(30);
	Texture background;
	background.loadFromFile("Textures/WhatsApp Image 2022-11-04 at 10.57.40 AM.jpeg");
	Sprite bg;
	bg.setTexture(background);
    Sprite player;
    Texture playerTex;
	playerTex.loadFromFile("Textures/player.png");
    player.setTexture(playerTex);
    player.setPosition(450.f, 300.f);
    int life = 3;
    int level = 1;
    bool pause=false;
    int Enemy_kill = 5;
    int score = 150;
    float Ymove = 3.f;
    Font font;
	font.loadFromFile("Fonts/Arial.ttf");
    Text scoreText;
    sf::Music Music1;

    scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(10.f, 10.f);

	Text lifeText;
	lifeText.setFont(font);
	lifeText.setCharacterSize(20);
	lifeText.setFillColor(Color::White);
	lifeText.setPosition(715.f, 10.f);
	Text gameOverText;
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(30);
	gameOverText.setStyle(Text::Bold);
	gameOverText.setFillColor(Color::Red);
	gameOverText.setPosition(340 , 250);
	gameOverText.setString("GAME OVER!");
	Text levelText;
	levelText.setFont(font);
	levelText.setCharacterSize(20);
	levelText.setFillColor(Color::White);
	levelText.setPosition(10.f, 32.f);
	Text levelDisplay;
	levelDisplay.setFont(font);
	levelDisplay.setCharacterSize(30);
	levelDisplay.setFillColor(Color::White);
	levelDisplay.setPosition(360 , window.getSize().y / 2);
    SoundBuffer buffer_background;
    Sound background_sound;
    SoundBuffer buffer_shoot;
    Sound shoot_sound;
    sf::SoundBuffer buffer_explosion;
    sf::Sound explosion_sound;
    buffer_background.loadFromFile("Audios/stranger_things.wav");
	background_sound.setBuffer(buffer_background);
	background_sound.setLoop(true);
	background_sound.play();
	buffer_shoot.loadFromFile("Audios/bom.wav");
    shoot_sound.setBuffer(buffer_shoot);
    Texture background3;
	background3.loadFromFile("Textures/WhatsApp Image 2022-11-04 at 7.07.12 AM.jpeg");
	Sprite bg3;
	bg3.setTexture(background3);



//game loop:
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
            {
                background_sound.pause();
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                background_sound.pause();
                window.close();
            }
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)){
            player.move(-5.f, 0.f);
             player.rotate(1);
            }
        if (Keyboard::isKeyPressed(Keyboard::Right)){
            player.move(5.f, 0.f);
            player.rotate(-1);
            }
        if (Keyboard::isKeyPressed(Keyboard::Up)){
            player.move(0.f, -5.f);
            	if(score>0){
                    score-=1;
            }

            }

        if (Keyboard::isKeyPressed(Keyboard::Down)){
            player.move(0.f, 5.f);
            }
        player.move(0.f, 2.f);


//landing condtions
               if(player.getPosition().y>430 && player.getPosition().x<=430 )
                {
                background_sound.pause();
                gameover();
               }else if(player.getPosition().y>430 && player.getPosition().x>=530){
                 background_sound.pause();
                gameover();
               }else if(player.getPosition().y>430 && player.getPosition().x>=431 && player.getPosition().x<=529 ){
                 background_sound.pause();
                win();
               }else if(player.getPosition().y<=0 ){
                 background_sound.pause();
                gameover();
                }


                if(score==0){
                background_sound.pause();
                gameover();
                }
        //UI Update

        scoreText.setString("petrol : " + std::to_string(score));

		window.clear();

		window.draw(bg);
        window.draw(player);


        window.draw(scoreText);
        window.draw(lifeText);
        window.draw(levelText);
        window.display();

        if(life <= 0){
            window.close();}

	}

	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 1;
            }

        }
        window.display();
    }


	return 0;
}

//FUNCTIONS
void main1()
{
    main2 = 1;
    RenderWindow window(VideoMode(800, 600), "Space Mission Game");
    Texture background;
	background.loadFromFile("Textures/WhatsApp Image 2022-11-04 at 7.07.12 AM.jpeg");
	Sprite bg;
	bg.setTexture(background);

    while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code==sf::Keyboard::Enter)
                {
                    main();
                }

                  if (event.key.code==sf::Keyboard::Escape)  //close
                  {
                     window.close();
                    exit(0);
                    }

                  if ( Keyboard::isKeyPressed(Keyboard::LControl))
                  {
                      instructions();
                  }

                if ( Keyboard::isKeyPressed(Keyboard::RControl))
                  {
                      instructions();
                  }
            }
            window.clear();
            window.draw(bg);
            window.display();
        }

    }

}

void instructions()
{
    RenderWindow window(VideoMode(800, 600), "Space Mission Game");

    Texture background;
	background.loadFromFile("Textures/WhatsApp Image 2022-11-04 at 7.52.09 AM.jpeg");
	Sprite bg;
	bg.setTexture(background);

    while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                  if (event.key.code==sf::Keyboard::Escape)  //close
                  {
                     main1();
                  }
            }
            window.clear();
            window.draw(bg);
            window.display();
        }
    }
}
void gameover()
{
    RenderWindow window(VideoMode(800, 600), "Space Mission Game");


    Texture background;
	background.loadFromFile("Textures/WhatsApp Image 2022-11-04 at 8.49.54 AM.jpeg");
	Sprite bg;
	bg.setTexture(background);

    while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{

                  if (event.key.code==sf::Keyboard::Escape)  //close
                  {
                     main1();
                  }

            }






            window.clear();
            window.draw(bg);
            window.display();

        }
    }

    void win()
{
    RenderWindow window(VideoMode(800, 600), "Space Mission Game");

    Texture background;
	background.loadFromFile("Textures/WhatsApp Image 2022-11-04 at 10.51.17 AM.jpeg");
	Sprite bg;
	bg.setTexture(background);

	/*buffer_shoot.loadFromFile("Audios/bom.wav");
    shoot_sound.setBuffer(buffer_shoot);*/

    while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
                  if (event.key.code==sf::Keyboard::Escape)  //close
                  {
                     main1();
                  }
            }
            window.clear();
            window.draw(bg);
            window.display();
        }
    }

