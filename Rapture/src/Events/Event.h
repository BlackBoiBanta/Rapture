#pragma once
#include "Core.h"

#include <functional>
#include <string>
#include <cstdint>
#include <sstream>
#include <iostream>

namespace Rapture
{
	using RAPT_UINT = std::uint32_t;

	enum class EventType : std::uint8_t
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender, 
		KeyPressed, KeyReleased, 
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCateg : std::uint8_t
	{
		None = 0,
		ApplicationCateg = BIT_FIELD(0),
		MouseCateg = BIT_FIELD(1),
		KeyboardCateg = BIT_FIELD(2),
		MouseButtonCateg = BIT_FIELD(3),
		InputCateg = BIT_FIELD(4)
	};

	class RAPT_API Event
	{
		friend class EventDispatcher;
	public: 
		virtual EventType getEventType()   const = 0;
		virtual const char* getEventName() const = 0;
		virtual EventCateg getCategField() const = 0;
		virtual std::string toString()     const { return getEventName(); }

		inline bool isInCateg(EventCateg categ)
		{
			return getCategField() & categ;
		}

	protected:
		bool m_handled = false;

	};


	class RAPT_API EventDispatcher
	{
		template <typename T>
		using EventFuncHandler = std::function<bool(T&)>;

#define DOWN_CAST(X, T) *((T*)&X)

	public:
		EventDispatcher(Event& eventObj)
			:m_event(eventObj)
		{}

		template <typename T>
		bool dispatch(EventFuncHandler<T> handler)
		{
			if (m_event.getEventType() == T::getStaticType())
			{
				m_event.m_handled = handler(DOWN_CAST(m_event, T));
				return true;
			}
			return false;
		}
	private:
		Event& m_event;
	};

	inline std::ostream& operator<<(std::ostream& out, const Event& obj)
	{
		std::cout << obj.toString();
		return out;
	}

#define SET_EVENT_NAME(name)		virtual const char* getEventName() const override { return #name; }
#define SET_EVENT_OBJ_TYPE(type)	virtual EventType getEventType() const override { return getEventTypeStatic(); }
#define SET_EVENT_STATIC_TYPE(type) static EventType getEventTypeStatic() { return EventType::##type; }


#define SET_EVENT_CATEGS(field)		 EventCateg getCategField(){ return field; }
#define SET_EVENT_TYPE(type)		SET_EVENT_NAME(type) SET_EVENT_OBJ_TYPE(type) SET_EVENT_STATIC_TYPE(type)



