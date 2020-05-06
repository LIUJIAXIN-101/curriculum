package servlets;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import main.UserManager;
import main.Validdation;

@WebServlet(name="Login",urlPatterns={"/Login.action"})
public class LoginServlet extends HttpServlet {
	private static final long serialVersionUID = -1L;
	
	
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		System.out.println("--------------------");
		doPost(request, response);
		return;
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

		String name = request.getParameter("username");
		String pass = request.getParameter("passwd");
		System.out.println("====," + name + "\tpasswd:" + pass);
		
		if(this.isValid(name, pass)){
			System.out.println("ok");
			request.getSession().setAttribute("user", name);
			request.getRequestDispatcher("/succ.jsp").forward(request,response);
		}
		else {
			System.out.println("failed");
		}
		
		/*	
		if(UserManager.getInstance().checkUserPassword(name, pass)) {
			System.out.println("=====================");
			request.getSession().setAttribute("user", name);
			request.getRequestDispatcher("/succ.jsp").forward(request,response);
		}else {
			request.getSession().setAttribute("info", "�û������벻ƥ��");
			request.getRequestDispatcher("/fail.jsp").forward(request,response);
		}
		*/		
	}
	
	private boolean isValid(String u, String p)
	{
		//return Validdation.isValid(u, p);
		return UserManager.getInstance().checkUserPassword(u, p);
		//return false;
	}
}