#include "Event.h"

namespace Rapture
{
	class RAPT_API KeyEvent : public Event
	{
	protected:
		KeyEvent(RAPT_UINT keyCode)
			:m_keyCode(keyCode)
		{}

		SET_EVENT_CATEGS(KeyboardCateg | InputCateg);
		inline RAPT_UINT getKeyCode() { return m_keyCode;  }
	
		RAPT_UINT m_keyCode;
	};

	class RAPT_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(RAPT_UINT keycode, RAPT_UINT repeatCount)
			:KeyEvent(keycode), m_repeatCount(repeatCount)
		{}

		SET_EVENT_TYPE(KeyPressed);

		inline bool getRepeatCount() { return m_repeatCount; }

		std::string toString() const override
		{
			std::stringstream info;
			info << "KeyPressedEvent: keyCode -> " << m_keyCode << " repeatCount -> " << m_repeatCount << " \n";
			return info.str();
		}

	private:
		RAPT_UINT m_repeatCount;

	};	
	
	class RAPT_API KeyReleasedEvent: public KeyEvent
	{
	public:
		KeyReleasedEvent(RAPT_UINT keycode)
			:KeyEvent(keycode)
		{}

		std::string toString() const override
		{
			std::stringstream info; 
			info << "KeyReleasedEvent: keyCode -> " << m_keyCode << " \n";
			return info.str();
		}

		SET_EVENT_TYPE(KeyReleased);

	};

}