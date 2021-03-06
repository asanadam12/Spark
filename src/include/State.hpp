#ifndef STATE_HPP
#define STATE_HPP

#include "modules.hpp"

class State; // Declare State struct

struct StateData
{
	/* Container Class for State Class*/

	Json::Value gfxSettings;

	std::stack<State*>* states;

	sf::RenderWindow* window;

	sf::Font* mainFont;

	std::map<std::string, int>* suppKeys;
};


class State
{
private:
	// For Quit checking 
	bool m_quit;
public:
	// Constructors/Destructors
	State();
	virtual ~State();

	// Accessors
	const  bool& getQuit() const;

	// Functions	
	void quitState(); 

	// Handle SFML Events
	virtual void handleEvents(sf::Event& events) = 0;

	// Update interface
	virtual void update(const float& dt) = 0;

	// Render interface
	virtual void render() = 0;

	// Static members
	static Json::Value readJSONConfig(const char* path);
	
};

#endif // STATE_HPP
