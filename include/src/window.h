#include <ncurses.h>

namespace ncursespp {
	class Window {
		public:
			Window();
			Window(std::shared_ptr<Window> parent);
			~Window();

			/**
			 * inserting text
			 */
			void move_cur(int y, int x);
			int get_ch();
			std::string get_nstr(int n);
			void flush_inp();
			void add_ch(int y, int x, char c);
			void add_ch(char c);
			void ins_ch(int y, int x, char c);
			void ins_ch(char c);
			void add_str(int y, int x, std::string s);
			void add_str(std::string s);
			// insertln
			void ins_ln(int y, int x);
			void ins_ln();
			// ungetchar
			void put_char(char c);
			void box(char c_y, char c_x);
			void h_line(char c, int n);
			void v_line(char c, int n);
			// overlay(w, w), overwrite(w, w), copywin(w, w, i, i, i, i, i, i, b), dupwin(w)

			/**
			 * deleting text
			 */
			void del_ch(int y, int x);
			void del_ch();
			void del_ln(int y, int x);
			void del_ln();
			// clrtoeol
			void clr_eol(int y, int x);
			void clr_eol();
			// clrtobot
			void clr_bot(int y, int x);
			void clr_bot();
			void clear();
			void erase();

			/**
			 * misc. text manipulation
			 */
			void scroll(int n);
			// scr_dump(s), putwin()
			// scr_restore(s), [WINDOW *] getwin()

			/**
			 * window management
			 */
			void refresh();
			void touch();
			void touch_ln(int y, int n);
			// mvwin
			void move(int y, int x);

			// getmaxyx
			int get_max_y();
			int get_max_x();

			// getyx
			int get_y();
			int get_x();

		private:
			static void initialize();
			static void endwin();

			WINDOW *w;
	};
}
