

// 这个类用来实现登录时的校验.
@WebServlet("/login")
public class LoginServlet extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 1. 先从请求中拿到用户名和密码.
        // 为了保证读出来的参数也能支持中文, 要记得设置请求的编码方式是 utf8
        req.setCharacterEncoding("utf8");
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        // 2. 验证用户名密码是否正确
        if (username == null || password == null || username.equals("") || password.equals("")) {
            resp.setContentType("text/html; charset=utf8");
            resp.getWriter().write("当前输入的用户名或密码不能为空!");
            return;
        }
        // 此处假定用户名只能是 zhangsan 或者 lisi. 密码都是 123
        // 正常的登录逻辑, 验证用户名密码都是从数据库读取的.
        if (!username.equals("zhangsan") && !username.equals("lisi")) {
            // 用户名有问题
            resp.setContentType("text/html; charset=utf8");
            resp.getWriter().write("用户名或密码有误");
            return;
        }
        if (!password.equals("123")) {
            // 密码有问题
            resp.setContentType("text/html; charset=utf8");
            resp.getWriter().write("用户名或密码有误");
            return;
        }
        // 3. 用户名和密码验证 ok, 接下来就创建一个会话.
        //    当前用户处于未登录的状态, 此时请求的 cookie 中没有 sessionId
        //    此处的 getSession 是无法从服务器的 哈希表 中找到该 session 对象的.
        //    由于此处把参数设为 true 了, 所以就允许 getSession 在查询不到的时候, 创建新的 session 对象和 sessionId
        //    并且会自动的把这个 sessionId 和 session 对象存储的 哈希表 中.
        //    同时返回这个 session 对象, 并且在接下来的响应中会自动把这个 sessionId 返回给客户端浏览器.
        HttpSession session = req.getSession(true);
        // 接下来可以让刚刚创建好的 session 对象存储咱们自定义的数据. 就可以在这个对象中存储用户的身份信息.
        session.setAttribute("username", username);
        // 4. 登录成功之后, 自动跳转到 主页
        resp.sendRedirect("index");
    }
}

