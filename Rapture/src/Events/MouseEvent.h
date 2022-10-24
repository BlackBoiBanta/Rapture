#include "Event.h"

namespace Rapture
{
	class RAPT_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float xPos, float yPos)
			:m_xPos(xPos), m_yPos(yPos)
		{}

		inline float getXpos() const { return m_xPos; }
		inline float getYpos() const { return m_yPos; }

		SET_EVENT_CATEGS(MouseCateg | InputCateg);
		SET_EVENT_TYPE(MouseMoved);

		std::string toString() const override
		{
			std::stringstream info;
			info << "MouseMovedEvent: xPos -> " << m_xPos << " yPos -> " << m_yPos << "\n";
			return info.str();
		}

	private:
		float m_xPos, m_yPos;
	};

	class RAPT_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			:m_xOffset(xOffset), m_yOffset(yOffset)
		{}

		inline float getXoffset() const { return m_xOffset; }
		inline float getYoffset() const { return m_yOffset; }

		SET_EVENT_CATEGS(InputCateg | MouseCateg);
		SET_EVENT_TYPE(MouseScrolled);

		std::string toString() const override
		{
			std::stringstream info;
			info << "MouseMovedEvent: xOffset -> " << m_xOffset << " yOffset -> " << m_yOffset << "\n";
			return info.str();
		}
	private:
		float m_xOffset, m_yOffset;
	};

	class RAPT_API MouseButtonEvent : public Event
	{
	protected:
		MouseButtonEvent(RAPT_UINT button)
			:m_button(button)
		{}

		inline RAPT_UINT getMouseButton() const { return m_button; }
		SET_EVENT_CATEGS(MouseCateg | InputCateg);

		RAPT_UINT m_button;
	};
}